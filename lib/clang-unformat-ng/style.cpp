#include "clang-unformat-ng/style.hpp"

#include "common-internal.hpp"
#include "enchantum/entries.hpp"

#include <_abort.h>
#include <clang/Format/Format.h>

#include <array>

#include <effolkronium/random.hpp>
#include <enchantum/enchantum.hpp>
#include <fmt/format.h>
#include <rfl.hpp>
#include <rfl/json.hpp>

namespace unformat {

// fmt: off
// /// Returns a format style complying with the LLVM coding standards:
// /// http://llvm.org/docs/CodingStandards.html.
// FormatStyle getLLVMStyle(FormatStyle::LanguageKind Language = FormatStyle::LK_Cpp);

// /// Returns a format style complying with one of Google's style guides:
// /// http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml.
// /// http://google-styleguide.googlecode.com/svn/trunk/javascriptguide.xml.
// /// https://developers.google.com/protocol-buffers/docs/style.
// FormatStyle getGoogleStyle(FormatStyle::LanguageKind Language);

// /// Returns a format style complying with Chromium's style guide:
// /// http://www.chromium.org/developers/coding-style.
// FormatStyle getChromiumStyle(FormatStyle::LanguageKind Language);

// /// Returns a format style complying with Mozilla's style guide:
// /// https://firefox-source-docs.mozilla.org/code-quality/coding-style/index.html.
// FormatStyle getMozillaStyle();

// /// Returns a format style complying with Webkit's style guide:
// /// http://www.webkit.org/coding/coding-style.html
// FormatStyle getWebKitStyle();

// /// Returns a format style complying with GNU Coding Standards:
// /// http://www.gnu.org/prep/standards/standards.html
// FormatStyle getGNUStyle();

// /// Returns a format style complying with Microsoft style guide:
// /// https://docs.microsoft.com/en-us/visualstudio/ide/editorconfig-code-style-settings-reference?view=vs-2017
// FormatStyle getMicrosoftStyle(FormatStyle::LanguageKind Language);

// FormatStyle getClangFormatStyle();

// /// Returns style indicating formatting should be not applied at all.
// FormatStyle getNoStyle();
// fmt: on

using clang::format::FormatStyle;
using clang::format::FormattingAttemptStatus;

// enum class builtin_style_t {
//     none = 0,
//     llvm,
//     google,
//     chromium,
//     mozilla,
//     webkit,
//     gnu,
//     microsoft,
//     clang_format,
// };

const FormatStyle &get_style(builtin_style_t style) {
    static std::array<FormatStyle, enchantum::count<builtin_style_t>> builtin_styles{};
    static std::once_flag generated;
    std::call_once(generated, []() {
        for (const auto &[val, str] : enchantum::entries<builtin_style_t>) {
            fmt::print("val: {} str: {}\n", enchantum::to_string(val), str);
            using sty = builtin_style_t;
            switch (val) {
            case sty::none:
                builtin_styles[enchantum::to_underlying(sty::none)] = clang::format::getNoStyle();
                break;
            case sty::llvm:
                builtin_styles[enchantum::to_underlying(sty::llvm)] = clang::format::getLLVMStyle();
                break;
            case sty::google:
                builtin_styles[enchantum::to_underlying(sty::google)] =
                    clang::format::getGoogleStyle(FormatStyle::LK_Cpp);
                break;
            case sty::chromium:
                builtin_styles[enchantum::to_underlying(sty::chromium)] =
                    clang::format::getChromiumStyle(FormatStyle::LK_Cpp);
                break;
            case sty::mozilla:
                builtin_styles[enchantum::to_underlying(sty::mozilla)] = clang::format::getMozillaStyle();
                break;
            case sty::webkit:
                builtin_styles[enchantum::to_underlying(sty::webkit)] = clang::format::getWebKitStyle();
                break;
            case sty::gnu:
                builtin_styles[enchantum::to_underlying(sty::gnu)] = clang::format::getGNUStyle();
                break;
            case sty::microsoft:
                builtin_styles[enchantum::to_underlying(sty::microsoft)] =
                    clang::format::getMicrosoftStyle(FormatStyle::LK_Cpp);
                break;
            case sty::clang_format:
                builtin_styles[enchantum::to_underlying(sty::clang_format)] = clang::format::getClangFormatStyle();
                break;
            default:
                abort();
                break;
            }
        }
    });
    return builtin_styles[style];
}

enum builtin_style_t random_style_enum() {
    return builtin_style_t::llvm;
}

const FormatStyle random_style() {
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
    return clang::format::getNoStyle();
}

}; // namespace unformat
