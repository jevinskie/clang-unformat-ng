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

using Rand = effolkronium::random_local;

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
                builtin_styles[std::to_underlying(sty::none)] = clang::format::getNoStyle();
                break;
            case sty::llvm:
                builtin_styles[std::to_underlying(sty::llvm)] = clang::format::getLLVMStyle();
                break;
            case sty::google:
                builtin_styles[std::to_underlying(sty::google)] = clang::format::getGoogleStyle(FormatStyle::LK_Cpp);
                break;
            case sty::chromium:
                builtin_styles[std::to_underlying(sty::chromium)] =
                    clang::format::getChromiumStyle(FormatStyle::LK_Cpp);
                break;
            case sty::mozilla:
                builtin_styles[std::to_underlying(sty::mozilla)] = clang::format::getMozillaStyle();
                break;
            case sty::webkit:
                builtin_styles[std::to_underlying(sty::webkit)] = clang::format::getWebKitStyle();
                break;
            case sty::gnu:
                builtin_styles[std::to_underlying(sty::gnu)] = clang::format::getGNUStyle();
                break;
            case sty::microsoft:
                builtin_styles[std::to_underlying(sty::microsoft)] =
                    clang::format::getMicrosoftStyle(FormatStyle::LK_Cpp);
                break;
            case sty::clang_format:
                builtin_styles[std::to_underlying(sty::clang_format)] = clang::format::getClangFormatStyle();
                break;
            default:
                abort();
                break;
            }
        }
    });
    return builtin_styles[std::to_underlying(style)];
}

builtin_style_t random_style_enum() {
    static Rand local_rand;
    // this is dumb, there is no thread-safety in local_rand.get()
    static std::once_flag rand_init;
    std::call_once(rand_init, []() {
        local_rand = Rand{};
    });
    return builtin_style_t{
        local_rand.get<std::underlying_type_t<builtin_style_t>>(0, enchantum::count<builtin_style_t>)};
}

const clang::format::FormatStyle &random_style() {
    return get_style(random_style_enum());
}

std::string_view style_name(builtin_style_t style) {
    return enchantum::to_string(style);
}

}; // namespace unformat
