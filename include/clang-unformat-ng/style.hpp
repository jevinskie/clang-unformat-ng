#pragma once

#include "common.hpp"

#include <string>

#include <clang/Format/Format.h>

namespace unformat {
namespace style {
struct Type {
    std::string cxx_name;
    std::string yaml_name;
    bool is_list;
    bool is_optional;
    bool is_deprecated;
};
}; // namespace style

enum class builtin_style_t {
    none = 0,
    llvm,
    google,
    chromium,
    mozilla,
    webkit,
    gnu,
    microsoft,
    clang_format,
};

const clang::format::FormatStyle &get_style(builtin_style_t style);
builtin_style_t random_style_enum();

}; // namespace unformat
