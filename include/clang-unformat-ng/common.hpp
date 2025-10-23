#pragma once

#include <cassert>
#include <cerrno>
#include <cstdlib>

#if 1
#include <string>
using string_t = std::string;
#else
#include <stringzilla/stringzilla.hpp>
using string_t = ashvardanian::stringzilla::string;
#endif
