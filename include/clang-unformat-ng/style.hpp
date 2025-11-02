#pragma once

#include <clang-unformat-ng/common.hpp>

#include <optional>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

#include <rfl.hpp>

#ifndef UNFMTNG_DISABLE_LLVM
#include <clang/Format/Format.h>
#else
#include <clang-unformat-ng/llvm-stubs.hpp>
#endif

namespace unformat {

namespace style {
struct Type {
    std::string cxx_name;
    std::string yaml_name;
    bool is_list;
    bool is_optional;
    bool is_deprecated;
};

struct Version {
    unsigned major;
    std::optional<unsigned> minor;
};

struct EnumValue {
    std::string name;
    std::string config;
};

struct Enum {
    std::string name;
    Type type;
    std::vector<EnumValue> values;
};

struct NestedEnum {
    std::string name;
    Type type;
    std::optional<Version> version;
    std::vector<EnumValue> values;
};

struct NestedField {
    std::string name;
    Type type;
    std::optional<Version> version;
};

using NestedStructValue = std::variant<NestedEnum, NestedField>;

struct NestedStruct {
    std::string name;
    Type type;
    std::vector<NestedStructValue> values;
};

struct Option {
    std::string name;
    Type type;
    std::optional<Version> version;
    rfl::Rename<"enum", std::optional<Enum>> enum_;
    std::optional<NestedStruct> nested_struct;
};
} // namespace style

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
const clang::format::FormatStyle &random_style();
builtin_style_t random_style_enum();
std::string_view style_name(builtin_style_t style);

} // namespace unformat
