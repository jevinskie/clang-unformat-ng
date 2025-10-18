#include "clang-unformat-ng/style.hpp"

#include "common-internal.hpp"

#include <array>
#include <mutex>

#include <clang/Format/Format.h>

#include <effolkronium/random.hpp>
#include <enchantum/enchantum.hpp>
#include <fmt/format.h>
#include <rfl.hpp>
#include <rfl/json.hpp>

namespace unformat {

using clang::format::FormatStyle;

const FormatStyle &get_style(builtin_style_t style) {
    static std::array<FormatStyle, enchantum::count<builtin_style_t>> builtin_styles{};
    static std::once_flag generated;
    std::call_once(generated, []() {
        for (const auto &[val, str] : enchantum::entries<builtin_style_t>) {
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
    static effolkronium::random_local local_rand;
    // this is dumb, there is no thread-safety in local_rand.get()
    static std::once_flag rand_init;
    std::call_once(rand_init, []() {
        local_rand = {};
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
