#include <map>
#include <regex>
#include <set>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

#include <clang/AST/Decl.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/Basic/TargetOptions.h>
#include <clang/Frontend/TextDiagnosticPrinter.h>
#include <clang/Rewrite/Core/Rewriter.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Core/Replacement.h>
#include <clang/Tooling/Refactoring.h>
#include <clang/Tooling/Tooling.h>
#include <clang/Tooling/Transformer/MatchConsumer.h>
#include <clang/Tooling/Transformer/RewriteRule.h>
#include <clang/Tooling/Transformer/Stencil.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/raw_ostream.h>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

using namespace clang;
using namespace ast_matchers;
using namespace transformer;

static_assert(std::ranges::range<clang::tooling::Replacements>);

template <> struct fmt::formatter<clang::tooling::Replacement> {
    constexpr auto parse(fmt::format_parse_context &ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }
    constexpr auto format(const clang::tooling::Replacement &r, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "Replacement {{ ");
        fmt::format_to(ctx.out(), "{}", r.toString());
        fmt::format_to(ctx.out(), " }}");
        return ctx.out();
    }
};

#if 0
template <> struct fmt::formatter<clang::tooling::Replacements> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const clang::tooling::Replacements &rs, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "Replacements {{ ");
        fmt::format_to(ctx.out(), "{}", fmt::join(rs, " "));
        fmt::format_to(ctx.out(), " }}");
        return ctx.out();
    }
};
#endif

// https://github.com/shao-hua-li/UBGen

namespace ruleactioncallback {

class RuleActionCallback : public clang::ast_matchers::MatchFinder::MatchCallback {
public:
    RuleActionCallback(clang::transformer::RewriteRuleWith<void> Rule,
                       std::map<std::string, clang::tooling::Replacements> &FileToReplacements,
                       std::map<std::string, int> &FileToNumberValueTrackers);
    void run(const clang::ast_matchers::MatchFinder::MatchResult &Result) override;
    void registerMatchers(clang::ast_matchers::MatchFinder &Finder);
    std::string getFunctionAsText(const clang::Decl *F, const clang::SourceManager &SM, const clang::LangOptions &lp);

private:
    clang::transformer::RewriteRuleWith<void> Rule;
    std::map<std::string, clang::tooling::Replacements> &FileToReplacements;
    std::map<std::string, int> &FileToNumberValueTrackers;
};

std::string GetFilenameFromRange(const CharSourceRange &R, const SourceManager &SM);
RangeSelector startOfFile(std::string ID);

} // namespace ruleactioncallback

std::string ruleactioncallback::GetFilenameFromRange(const CharSourceRange &R, const SourceManager &SM) {
    const std::pair<FileID, unsigned> DecomposedLocation = SM.getDecomposedLoc(SM.getSpellingLoc(R.getBegin()));
    const FileEntry *Entry                               = SM.getFileEntryForID(DecomposedLocation.first);
    return std::string(Entry ? Entry->tryGetRealPathName() : "");
}

Expected<DynTypedNode> getNode(const ast_matchers::BoundNodes &Nodes, StringRef ID) {
    auto &NodesMap = Nodes.getMap();
    auto It        = NodesMap.find(ID);
    if (It == NodesMap.end())
        return llvm::make_error<llvm::StringError>(llvm::errc::invalid_argument, ID + "not bound");
    return It->second;
}

RangeSelector startOfFile(std::string ID) {
    return [ID](const clang::ast_matchers::MatchFinder::MatchResult &Result) -> Expected<CharSourceRange> {
        auto Node = getNode(Result.Nodes, ID);
        if (!Node)
            return Node.takeError();
        const auto &SM = Result.Context->getSourceManager();
        auto Start     = SM.getLocForStartOfFile(SM.getFileID(Node->getSourceRange().getBegin()));
        return CharSourceRange(SourceRange(Start), false);
    };
}

ruleactioncallback::RuleActionCallback::RuleActionCallback(
    RewriteRuleWith<void> Rule, std::map<std::string, clang::tooling::Replacements> &FileToReplacements,
    std::map<std::string, int> &FileToNumberValueTrackers)
    : Rule{Rule}, FileToReplacements{FileToReplacements}, FileToNumberValueTrackers{FileToNumberValueTrackers} {}

void ruleactioncallback::RuleActionCallback::run(const clang::ast_matchers::MatchFinder::MatchResult &Result) {

    if (Result.Context->getDiagnostics().hasErrorOccurred()) {
        llvm::errs() << "An error has occured.\n";
        return;
    }
    // Expected<SmallVector<transformer::Edit, 1>> Edits =
    //     transformer::detail::findSelectedCase(Result, Rule).Edits(Result);
    // if (!Edits) {
    //     llvm::errs() << "Rewrite failed: " << llvm::toString(Edits.takeError()) << "\n";
    //     return;
    // }
    const auto sel_case = transformer::detail::findSelectedCase(Result, Rule);
    // if (1 != transformer::detail::findSelectedCase(Result, Rule)) {
    //     llvm::errs() << "Rewrite failed: " << Rule.Metadata.begin()->get()->toString() << "\n";
    //     return;
    // }
    auto SM        = Result.SourceManager;
    const auto &EG = Rule.Cases[sel_case].Edits;
    // const auto &EGV = EG(Result);
    // const auto &EGV = flatten(EG);
    Expected<SmallVector<transformer::Edit, 1>> Edits = EG(Result);
    if (!Edits) {
        llvm::errs() << "Rewrite failed: " << llvm::toString(Edits.takeError()) << "\n";
        return;
    }
    for (const auto &T : *Edits) {
        auto FilePath      = GetFilenameFromRange(T.Range, *SM);
        auto N             = FileToNumberValueTrackers[FilePath]++;
        auto R             = tooling::Replacement(*SM, T.Range, T.Replacement);
        auto &Replacements = FileToReplacements[FilePath];
        auto Err           = Replacements.add(R);
        if (Err) {
            auto NewOffset = Replacements.getShiftedCodePosition(R.getOffset());
            auto NewLength = Replacements.getShiftedCodePosition(R.getOffset() + R.getLength()) - NewOffset;
            if (NewLength == R.getLength()) {
                R = clang::tooling::Replacement(R.getFilePath(), NewOffset, NewLength, R.getReplacementText());
                Replacements = Replacements.merge(tooling::Replacements(R));
            } else {
                llvm_unreachable(llvm::toString(std::move(Err)).c_str());
            }
        }
    }
}

void ruleactioncallback::RuleActionCallback::registerMatchers(clang::ast_matchers::MatchFinder &Finder) {
    for (auto &Matcher : transformer::detail::buildMatchers(Rule))
        Finder.addDynamicMatcher(Matcher.withTraversalKind(clang::TK_IgnoreUnlessSpelledInSource), this);
}

class AddBraces {
public:
    AddBraces(std::map<std::string, clang::tooling::Replacements> &FileToReplacements);
    AddBraces(const AddBraces &) = delete;
    AddBraces(AddBraces &&)      = delete;

    void registerMatchers(clang::ast_matchers::MatchFinder &Finder);

private:
    std::map<std::string, clang::tooling::Replacements> &FileToReplacements;
    std::vector<ruleactioncallback::RuleActionCallback> Callbacks;
    std::map<std::string, int> FileToNumberValueTrackers;
};

namespace {

/* Self-defined computations/actions */

// add braces around if/while/for/switch nodes
auto curlyBraceAction = {insertBefore(statement("stmt"), cat("{\n")), insertAfter(statement("stmt"), cat("\n}"))};

/* Matchers and Rules */

AST_MATCHER_P(CaseStmt, isCaseSubStmt, ast_matchers::internal::Matcher<Stmt>, InnerMatcher) {
    const auto *SubStmt = Node.getSubStmt();
    return (SubStmt != nullptr && InnerMatcher.matches(*SubStmt, Finder, Builder));
}

AST_MATCHER_P(DefaultStmt, isDefaultSubStmt, ast_matchers::internal::Matcher<Stmt>, InnerMatcher) {
    const auto *SubStmt = Node.getSubStmt();
    return (SubStmt != nullptr && InnerMatcher.matches(*SubStmt, Finder, Builder));
}

// rule for if/then statements without braces
auto canonicalizeIfThenRule() {
    return makeRule(ifStmt(isExpansionInMainFile(), hasThen(stmt(unless(compoundStmt())).bind("stmt"))),
                    curlyBraceAction);
}
// rule for if/else statements without braces
auto canonicalizeIfElseRule() {
    return makeRule(ifStmt(isExpansionInMainFile(), hasElse(stmt(unless(compoundStmt())).bind("stmt"))),
                    curlyBraceAction);
}
// rule for loop statements without braces
auto canonicalizeLoopRule() {
    return makeRule(mapAnyOf(forStmt, whileStmt, doStmt, cxxForRangeStmt)
                        .with(isExpansionInMainFile(), hasBody(stmt(unless(compoundStmt())).bind("stmt"))),
                    curlyBraceAction);
}
// rule for switch statements without braces
auto canonicalizeSwitchRule() {
    auto Unless = unless(anyOf(compoundStmt(), caseStmt(), defaultStmt()));
    return applyFirst(
        {makeRule(caseStmt(isExpansionInMainFile(), isCaseSubStmt(stmt(Unless).bind("stmt"))), curlyBraceAction),
         makeRule(defaultStmt(isExpansionInMainFile(), isDefaultSubStmt(stmt(Unless).bind("stmt"))),
                  curlyBraceAction)});
}

} // namespace

AddBraces::AddBraces(std::map<std::string, clang::tooling::Replacements> &FileToReplacements)
    : FileToReplacements{FileToReplacements} {

    // canonicalize rules
    Callbacks.emplace_back(ruleactioncallback::RuleActionCallback{canonicalizeIfThenRule(), FileToReplacements,
                                                                  FileToNumberValueTrackers});
    Callbacks.emplace_back(ruleactioncallback::RuleActionCallback{canonicalizeIfElseRule(), FileToReplacements,
                                                                  FileToNumberValueTrackers});
    Callbacks.emplace_back(
        ruleactioncallback::RuleActionCallback{canonicalizeLoopRule(), FileToReplacements, FileToNumberValueTrackers});
    Callbacks.emplace_back(ruleactioncallback::RuleActionCallback{canonicalizeSwitchRule(), FileToReplacements,
                                                                  FileToNumberValueTrackers});
}

void AddBraces::registerMatchers(clang::ast_matchers::MatchFinder &Finder) {
    for (auto &Callback : Callbacks)
        Callback.registerMatchers(Finder);
}

using namespace llvm;

namespace {

cl::OptionCategory ToolOptions("options");

bool applyReplacements(clang::tooling::RefactoringTool &Tool) {
    LangOptions DefaultLangOptions;
    IntrusiveRefCntPtr<DiagnosticOptions> DiagOpts = new DiagnosticOptions();
    clang::TextDiagnosticPrinter DiagnosticPrinter(errs(), &*DiagOpts);
    DiagnosticsEngine Diagnostics(IntrusiveRefCntPtr<DiagnosticIDs>(new DiagnosticIDs()), &*DiagOpts,
                                  &DiagnosticPrinter, false);
    auto &FileMgr = Tool.getFiles();
    SourceManager Sources(Diagnostics, FileMgr);

    Rewriter Rewrite(Sources, DefaultLangOptions);

    bool Result = true;
    for (const auto &FileAndReplaces :
         groupReplacementsByFile(Rewrite.getSourceMgr().getFileManager(), Tool.getReplacements())) {
        auto &CurReplaces = FileAndReplaces.second;

        Result = applyAllReplacements(CurReplaces, Rewrite) && Result;
    }
    if (!Result) {
        llvm::errs() << "Failed applying all replacements.\n";
        return false;
    }

    return !Rewrite.overwriteChangedFiles();
}

template <typename InstrTool> int runToolOnCode(clang::tooling::RefactoringTool &Tool) {
    auto &replacements = Tool.getReplacements();
    fmt::print("init replacements: {}\n", replacements);
    InstrTool Instr(replacements);
    ast_matchers::MatchFinder Finder;
    Instr.registerMatchers(Finder);
    std::unique_ptr<tooling::FrontendActionFactory> Factory = tooling::newFrontendActionFactory(&Finder);

    auto Ret = Tool.run(Factory.get());
    if (!Ret) {
        fmt::print("mid replacements: {}\n", Tool.getReplacements());
        if (!applyReplacements(Tool)) {
            fmt::print("error replacements: {}\n", Tool.getReplacements());
            llvm::errs() << "Failed to overwrite the input files.\n";
            return 1;
        }
    }

    fmt::print("good replacements: {}\n", Tool.getReplacements());

    return Ret;
}

} // namespace

int main(int argc, const char **argv) {
    auto ExpectedParser = clang::tooling::CommonOptionsParser::create(argc, argv, ToolOptions);
    if (!ExpectedParser) {
        llvm::errs() << ExpectedParser.takeError();
        return 1;
    }
    clang::tooling::CommonOptionsParser &OptionsParser = ExpectedParser.get();

    const auto &Compilations = OptionsParser.getCompilations();
    const auto &Files        = OptionsParser.getSourcePathList();
    fmt::print("Files: {}\n", fmt::join(Files, " "));
    clang::tooling::RefactoringTool Tool(Compilations, Files);
    int Result = 0;
    Result     = runToolOnCode<AddBraces>(Tool);

    if (Result) {
        llvm::errs() << "Something went wrong...\n";
        return Result;
    }

    return 0;
}
