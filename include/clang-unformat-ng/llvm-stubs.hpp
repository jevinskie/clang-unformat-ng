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
