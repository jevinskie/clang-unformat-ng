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
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/raw_ostream.h>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

using namespace llvm;
using namespace clang;
using namespace ast_matchers;
using namespace transformer;
using clang::tooling::Replacements;

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

#if 0
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

cl::OptionCategory UnformatOptionsCategory("unformat");

bool applyReplacements(clang::tooling::RefactoringTool &Tool) {
    LangOptions DefaultLangOptions;
    DiagnosticOptions DiagOpts;
    clang::TextDiagnosticPrinter DiagnosticPrinter(errs(), DiagOpts);
    DiagnosticsEngine Diagnostics(DiagnosticIDs::create(), DiagOpts, &DiagnosticPrinter, false);
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
#endif

#if 0
namespace {
// Returns true on error.
static bool format(StringRef FileName) {
    using namespace clang::format;
    using namespace clang::tooling;
    const bool IsSTDIN = FileName == "-";
    if (!OutputXML && Inplace && IsSTDIN) {
        errs() << "error: cannot use -i when reading from stdin.\n";
        return true;
    }
    // On Windows, overwriting a file with an open file mapping doesn't work,
    // so read the whole file into memory when formatting in-place.
    ErrorOr<std::unique_ptr<MemoryBuffer>> CodeOrErr = !OutputXML && Inplace
                                                           ? MemoryBuffer::getFileAsStream(FileName)
                                                           : MemoryBuffer::getFileOrSTDIN(FileName, /*IsText=*/true);
    if (std::error_code EC = CodeOrErr.getError()) {
        errs() << FileName << ": " << EC.message() << "\n";
        return true;
    }
    std::unique_ptr<llvm::MemoryBuffer> Code = std::move(CodeOrErr.get());
    if (Code->getBufferSize() == 0)
        return false; // Empty files are formatted correctly.

    StringRef BufStr = Code->getBuffer();

    const char *InvalidBOM = SrcMgr::ContentCache::getInvalidBOM(BufStr);

    if (InvalidBOM) {
        errs() << "error: encoding with unsupported byte order mark \"" << InvalidBOM << "\" detected";
        if (!IsSTDIN)
            errs() << " in file '" << FileName << "'";
        errs() << ".\n";
        return true;
    }

    std::vector<tooling::Range> Ranges;
    if (fillRanges(Code.get(), Ranges))
        return true;
    StringRef AssumedFileName = IsSTDIN ? AssumeFileName : FileName;
    if (AssumedFileName.empty()) {
        llvm::errs() << "error: empty filenames are not allowed\n";
        return true;
    }

    Expected<clang::format::FormatStyle> FormatStyle = getStyle(
        Style, AssumedFileName, FallbackStyle, Code->getBuffer(), nullptr, WNoErrorList.isSet(WNoError::Unknown));
    if (!FormatStyle) {
        llvm::errs() << toString(FormatStyle.takeError()) << "\n";
        return true;
    }

    StringRef QualifierAlignmentOrder = QualifierAlignment;

    FormatStyle->QualifierAlignment =
        StringSwitch<FormatStyle::QualifierAlignmentStyle>(QualifierAlignmentOrder.lower())
            .Case("right", FormatStyle::QAS_Right)
            .Case("left", FormatStyle::QAS_Left)
            .Default(FormatStyle->QualifierAlignment);

    if (FormatStyle->QualifierAlignment == FormatStyle::QAS_Left) {
        FormatStyle->QualifierOrder = {"const", "volatile", "type"};
    } else if (FormatStyle->QualifierAlignment == FormatStyle::QAS_Right) {
        FormatStyle->QualifierOrder = {"type", "const", "volatile"};
    } else if (QualifierAlignmentOrder.contains("type")) {
        FormatStyle->QualifierAlignment = FormatStyle::QAS_Custom;
        SmallVector<StringRef> Qualifiers;
        QualifierAlignmentOrder.split(Qualifiers, " ", /*MaxSplit=*/-1,
                                      /*KeepEmpty=*/false);
        FormatStyle->QualifierOrder = {Qualifiers.begin(), Qualifiers.end()};
    }

    if (clang::format::SortIncludes.getNumOccurrences() != 0) {
        FormatStyle->SortIncludes = {};
        if (SortIncludes)
            FormatStyle->SortIncludes.Enabled = true;
    }
    unsigned CursorPosition = Cursor;
    Replacements Replaces   = sortIncludes(*FormatStyle, Code->getBuffer(), Ranges, AssumedFileName, &CursorPosition);

    const bool IsJson = FormatStyle->isJson();

    // To format JSON insert a variable to trick the code into thinking its
    // JavaScript.
    if (IsJson && !FormatStyle->DisableFormat) {
        auto Err = Replaces.add(tooling::Replacement(AssumedFileName, 0, 0, "x = "));
        if (Err)
            llvm::errs() << "Bad Json variable insertion\n";
    }

    auto ChangedCode = tooling::applyAllReplacements(Code->getBuffer(), Replaces);
    if (!ChangedCode) {
        llvm::errs() << toString(ChangedCode.takeError()) << "\n";
        return true;
    }
    // Get new affected ranges after sorting `#includes`.
    Ranges = tooling::calculateRangesAfterReplacements(Replaces, Ranges);
    FormattingAttemptStatus Status;
    Replacements FormatChanges = reformat(*FormatStyle, *ChangedCode, Ranges, AssumedFileName, &Status);
    Replaces                   = Replaces.merge(FormatChanges);
    if (DryRun) {
        return Replaces.size() > (IsJson ? 1u : 0u) && emitReplacementWarnings(Replaces, AssumedFileName, Code);
    }
    if (OutputXML) {
        outputXML(Replaces, FormatChanges, Status, Cursor, CursorPosition);
    } else {
        auto InMemoryFileSystem = makeIntrusiveRefCnt<llvm::vfs::InMemoryFileSystem>();
        FileManager Files(FileSystemOptions(), InMemoryFileSystem);

        DiagnosticOptions DiagOpts;
        ClangFormatDiagConsumer IgnoreDiagnostics;
        DiagnosticsEngine Diagnostics(DiagnosticIDs::create(), DiagOpts, &IgnoreDiagnostics, false);
        SourceManager Sources(Diagnostics, Files);
        FileID ID = createInMemoryFile(AssumedFileName, *Code, Sources, Files, InMemoryFileSystem.get());
        Rewriter Rewrite(Sources, LangOptions());
        tooling::applyAllReplacements(Replaces, Rewrite);
        if (Inplace) {
            if (Rewrite.overwriteChangedFiles())
                return true;
        } else {
            if (Cursor.getNumOccurrences() != 0) {
                outs() << "{ \"Cursor\": " << FormatChanges.getShiftedCodePosition(CursorPosition)
                       << ", \"IncompleteFormat\": " << (Status.FormatComplete ? "false" : "true");
                if (!Status.FormatComplete)
                    outs() << ", \"Line\": " << Status.Line;
                outs() << " }\n";
            }
            Rewrite.getEditBuffer(ID).write(outs());
        }
    }
    return !Status.FormatComplete;
}
} // namespace
#endif

namespace unformat {
namespace priv {
static cl::OptionCategory UnformatOptionsCategory("unformat");
static cl::list<std::string> FileNames(cl::Positional, cl::desc("[@<file>] [<file> ...]"),
                                       cl::cat(UnformatOptionsCategory));
}; // namespace priv
}; // namespace unformat

int main(int argc, const char **argv) {
    InitLLVM X(argc, argv);

    cl::HideUnrelatedOptions(unformat::priv::UnformatOptionsCategory);
    cl::ParseCommandLineOptions(argc, argv, "A tool to calculate \"optimal\" format styles from existing source.\n\n");

#if 0
    auto ExpectedParser = clang::tooling::CommonOptionsParser::create(argc, argv, UnformatOptionsCategory);
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
#endif

    return 0;
}
