#include <cstdio>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

// #include <clang/AST/Decl.h>
// #include <clang/ASTMatchers/ASTMatchFinder.h>
// #include <clang/ASTMatchers/ASTMatchers.h>
// #include <clang/Basic/TargetOptions.h>
// #include <clang/Frontend/TextDiagnosticPrinter.h>
// #include <clang/Rewrite/Core/Rewriter.h>
// #include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Core/Replacement.h>
// #include <clang/Tooling/Refactoring.h>
// #include <clang/Tooling/Tooling.h>
// #include <clang/Tooling/Transformer/MatchConsumer.h>
// #include <clang/Tooling/Transformer/RewriteRule.h>
// #include <clang/Tooling/Transformer/Stencil.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/raw_ostream.h>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

using namespace llvm;
using namespace clang;
// using namespace ast_matchers;
// using namespace transformer;
using clang::tooling::Replacements;

static_assert(std::ranges::range<clang::tooling::Replacements>);

template <> struct fmt::formatter<clang::tooling::Replacement> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const clang::tooling::Replacement &r, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "R1 {{ ");
        fmt::format_to(ctx.out(), "{}", r.toString());
        fmt::format_to(ctx.out(), " }}");
        return ctx.out();
    }
};

template <> struct fmt::formatter<clang::tooling::Replacements> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const clang::tooling::Replacements &rs, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "Rn {{ ");
        fmt::format_to(ctx.out(), "{}", fmt::join(rs, " "));
        fmt::format_to(ctx.out(), " }}");
        return ctx.out();
    }
};

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
static cl::list<std::string> FileNames(cl::Positional, cl::desc("[<file> ...]"), cl::cat(UnformatOptionsCategory));

void construct_memfs(const std::vector<std::string> fnames) {}

int priv_main() {
    std::vector<std::string> fnames(FileNames.begin(), FileNames.end());
    for (const auto &f : fnames) {
        fmt::print("file: {}\n", f);
    }

    return 0;
}

}; // namespace priv
}; // namespace unformat

int main(int argc, const char **argv) {
    InitLLVM X(argc, argv);
    cl::HideUnrelatedOptions(unformat::priv::UnformatOptionsCategory);
    cl::ParseCommandLineOptions(argc, argv, "A tool to calculate \"optimal\" format styles from existing source.\n\n");
    int res = unformat::priv::priv_main();
    return res;
}
