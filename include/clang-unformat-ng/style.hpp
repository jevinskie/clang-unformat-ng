#pragma once

#include "common.hpp"

#include <string>

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
}; // namespace unformat
