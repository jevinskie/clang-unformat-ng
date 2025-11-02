#pragma once

#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace llvm {
using StringRef                      = std::string_view;
template <typename T> using ArrayRef = std::span<const T>;
} // namespace llvm

namespace clang {
namespace tooling {

struct Range {
    unsigned int offset;
    unsigned int length;
};

struct Replacement {
    std::string toString() const {
        return {};
    }
};

struct Replacements {
    std::vector<Replacement> replacements;
    auto begin() const {
        return replacements.begin();
    }
    auto end() const {
        return replacements.end();
    }
};

struct SourceManager {};

} // namespace tooling

namespace format {

struct FormattingAttemptStatus {
    bool FormatComplete = true;
    unsigned Line       = 0;
};

struct FormatStyle {
    enum LanguageKind {
        LK_C,
        LK_Cpp,
        LK_None,
    };

    LanguageKind Language;
    int AccessModifierOffset;
    bool AllowAllArgumentsOnNextLine;
    bool AllowAllParametersOfDeclarationOnNextLine;
    bool AllowBreakBeforeQtProperty;
    bool AllowShortCaseExpressionOnASingleLine;
    bool AllowShortCaseLabelsOnASingleLine;
    bool AllowShortCompoundRequirementOnASingleLine;
    bool AllowShortEnumsOnASingleLine;
    bool AllowShortLoopsOnASingleLine;
    bool AllowShortNamespacesOnASingleLine;
    bool AlwaysBreakBeforeMultilineStrings;
    bool BinPackArguments;
    bool BinPackLongBracedList;
    int BracedInitializerIndentWidth;
    bool BreakAdjacentStringLiterals;
    bool BreakAfterJavaFieldAnnotations;
    bool BreakArrays;
    bool BreakBeforeTemplateCloser;
    bool BreakBeforeTernaryOperators;
    bool BreakFunctionDefinitionParameters;
    bool BreakStringLiterals;
    unsigned ColumnLimit;
    bool CompactNamespaces;
    unsigned ConstructorInitializerIndentWidth;
    unsigned ContinuationIndentWidth;
    bool Cpp11BracedListStyle;
    bool DerivePointerAlignment;
    bool DisableFormat;
    bool ExperimentalAutoDetectBinPacking;
    bool FixNamespaceComments;
    bool IndentAccessModifiers;
    bool IndentCaseBlocks;
    bool IndentCaseLabels;
    bool IndentExportBlock;
    bool IndentGotoLabels;
    bool IndentRequiresClause;
    unsigned IndentWidth;
    bool IndentWrappedFunctionNames;
    bool InsertBraces;
    bool InsertNewlineAtEOF;
    bool JavaScriptWrapImports;
    bool KeepFormFeed;
    unsigned MaxEmptyLinesToKeep;
    unsigned ObjCBlockIndentWidth;
    bool ObjCBreakBeforeNestedBlockParam;
    bool ObjCSpaceAfterProperty;
    bool ObjCSpaceBeforeProtocolList;
    int PPIndentWidth;
    unsigned PenaltyBreakAssignment;
    unsigned PenaltyBreakBeforeFirstCallParameter;
    unsigned PenaltyBreakBeforeMemberAccess;
    unsigned PenaltyBreakComment;
    unsigned PenaltyBreakFirstLessLess;
    unsigned PenaltyBreakOpenParenthesis;
    unsigned PenaltyBreakScopeResolution;
    unsigned PenaltyBreakString;
    unsigned PenaltyBreakTemplateDeclaration;
    unsigned PenaltyExcessCharacter;
    unsigned PenaltyIndentedWhitespace;
    unsigned PenaltyReturnTypeOnItsOwnLine;
    bool RemoveBracesLLVM;
    bool RemoveEmptyLinesInUnwrappedLines;
    bool RemoveSemicolon;
    unsigned ShortNamespaceLines;
    bool SkipMacroDefinitionBody;
    bool SpaceAfterCStyleCast;
    bool SpaceAfterLogicalNot;
    bool SpaceAfterOperatorKeyword;
    bool SpaceAfterTemplateKeyword;
    bool SpaceBeforeAssignmentOperators;
    bool SpaceBeforeCaseColon;
    bool SpaceBeforeCpp11BracedList;
    bool SpaceBeforeCtorInitializerColon;
    bool SpaceBeforeInheritanceColon;
    bool SpaceBeforeJsonColon;
    bool SpaceBeforeRangeBasedForLoopColon;
    bool SpaceBeforeSquareBrackets;
    unsigned SpacesBeforeTrailingComments;
    bool SpacesInContainerLiterals;
    bool SpacesInSquareBrackets;
    unsigned TabWidth;
    bool VerilogBreakBetweenInstancePorts;
};

FormatStyle getNoStyle();
FormatStyle getLLVMStyle(FormatStyle::LanguageKind Language = FormatStyle::LK_Cpp);
FormatStyle getGoogleStyle(FormatStyle::LanguageKind Language);
FormatStyle getChromiumStyle(FormatStyle::LanguageKind Language);
FormatStyle getMozillaStyle();
FormatStyle getWebKitStyle();
FormatStyle getGNUStyle();
FormatStyle getMicrosoftStyle(FormatStyle::LanguageKind Language);
FormatStyle getClangFormatStyle();
FormatStyle getNoStyle();

tooling::Replacements reformat(const FormatStyle &Style, llvm::StringRef Code, llvm::ArrayRef<tooling::Range> Ranges,
                               llvm::StringRef FileName = "<stdin>", FormattingAttemptStatus *Status = nullptr);
} // namespace format

} // namespace clang
