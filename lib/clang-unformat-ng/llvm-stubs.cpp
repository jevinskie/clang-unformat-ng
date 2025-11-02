#include <clang-unformat-ng/llvm-stubs.hpp>

#include "common-internal.hpp"

namespace clang {
namespace format {

FormatStyle getNoStyle() {
    return {};
}
FormatStyle getLLVMStyle(FormatStyle::LanguageKind Language) {
    return {.Language = Language};
}
FormatStyle getGoogleStyle(FormatStyle::LanguageKind Language) {
    return {.Language = Language};
}
FormatStyle getChromiumStyle(FormatStyle::LanguageKind Language) {
    return {.Language = Language};
}
FormatStyle getMozillaStyle() {
    return {};
}
FormatStyle getWebKitStyle() {
    return {};
}
FormatStyle getGNUStyle() {
    return {};
}
FormatStyle getMicrosoftStyle(FormatStyle::LanguageKind Language) {
    return {.Language = Language};
}
FormatStyle getClangFormatStyle() {
    return {};
}

tooling::Replacements reformat(const FormatStyle &Style, llvm::StringRef Code, llvm::ArrayRef<tooling::Range> Ranges,
                               llvm::StringRef FileName, FormattingAttemptStatus *Status) {
    return {};
}

} // namespace format
} // namespace clang
