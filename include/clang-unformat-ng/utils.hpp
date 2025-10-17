#pragma once

#include "common.hpp"

#include <cstdint>
#include <string>
#include <vector>

namespace unformat {
std::vector<uint8_t> slurp_file_bytes(const std::string &path);
std::string slurp_file_string(const std::string &path);
}; // namespace unformat
