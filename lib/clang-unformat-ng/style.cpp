#include "clang-unformat-ng/style.hpp"

#include "common-internal.hpp"

#include <clang/Format/Format.h>

#include <array>

#include <effolkronium/random.hpp>
#include <enchantum/enchantum.hpp>
#include <rfl.hpp>
#include <rfl/json.hpp>

namespace unformat {

// fmt: off
/// Returns a format style complying with the LLVM coding standards:
/// http://llvm.org/docs/CodingStandards.html.
FormatStyle getLLVMStyle(FormatStyle::LanguageKind Language = FormatStyle::LK_Cpp);

/// Returns a format style complying with one of Google's style guides:
/// http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml.
/// http://google-styleguide.googlecode.com/svn/trunk/javascriptguide.xml.
/// https://developers.google.com/protocol-buffers/docs/style.
FormatStyle getGoogleStyle(FormatStyle::LanguageKind Language);

/// Returns a format style complying with Chromium's style guide:
/// http://www.chromium.org/developers/coding-style.
FormatStyle getChromiumStyle(FormatStyle::LanguageKind Language);

/// Returns a format style complying with Mozilla's style guide:
/// https://firefox-source-docs.mozilla.org/code-quality/coding-style/index.html.
FormatStyle getMozillaStyle();

/// Returns a format style complying with Webkit's style guide:
/// http://www.webkit.org/coding/coding-style.html
FormatStyle getWebKitStyle();

/// Returns a format style complying with GNU Coding Standards:
/// http://www.gnu.org/prep/standards/standards.html
FormatStyle getGNUStyle();

/// Returns a format style complying with Microsoft style guide:
/// https://docs.microsoft.com/en-us/visualstudio/ide/editorconfig-code-style-settings-reference?view=vs-2017
FormatStyle getMicrosoftStyle(FormatStyle::LanguageKind Language);

FormatStyle getClangFormatStyle();

/// Returns style indicating formatting should be not applied at all.
FormatStyle getNoStyle();
// fmt: on

using clang::format::FormatStyle;
using clang::format::FormattingAttemptStatus;

enum builtin_style_t random_style_enum() {
    return builtin_style_t::llvm;
}

static const std::array<std::unique_ptr<FormatStyle>, enchantum::count<builtin_style_t>> builtin_styles{};

const FormatStyle &random_style() {
    static std::once_flag generated;
    std::call_once(generated, []() {
        std::cout << "Simple example: called once\n";
    });

    switch (random_style_enum()) {
    case builtin_style_t::llvm:
        return clang::format::getLLVMStyle();
        break;
    default:
        abort();
        break;
    }
    return getNoStyle();
}

}; // namespace unformat
