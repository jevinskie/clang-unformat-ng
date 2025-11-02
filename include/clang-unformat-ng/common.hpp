#pragma once

#include <clang-unformat-ng/config.hpp>

#include <cassert>
#include <cerrno>
#include <cstdlib>
#include <type_traits>

#if 1
#include <string>
using string_t = std::string;
#else
#include <stringzilla/stringzilla.hpp>
using string_t = ashvardanian::stringzilla::string;
#endif

namespace unformat {

template <typename T>
concept POD = std::is_trivial_v<T> && std::is_standard_layout_v<T>;

} // namespace unformat
