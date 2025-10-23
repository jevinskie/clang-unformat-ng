#pragma once

#include "common.hpp"

#include <span>
#include <string>
#include <vector>

#include <strong_type/strong_type.hpp>

namespace unformat {
std::string slurp_file_string(const std::string &path);

class UnixSocket {
public:
    UnixSocket(const std::string &path);
    std::vector<uint8_t> read(size_t size);
    void write(std::span<uint8_t> datagram);
    void disconnect();

private:
    const std::string _path;
    int _fd{-1};
};

}; // namespace unformat
