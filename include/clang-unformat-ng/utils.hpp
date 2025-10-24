#pragma once

#include "common.hpp"

#include <span>
#include <string>
#include <sys/un.h>
#include <vector>

namespace unformat {

std::string slurp_file_string(const std::string &path);

class UnixSocket {
public:
    UnixSocket(const std::string &path);
    std::vector<uint8_t> read(size_t size);
    void write(std::span<const uint8_t> buf);
    void shutdown();
    void connect();
    void bind();
    void listen();

private:
    const std::string _path;
    struct sockaddr_un _addr;
    int _fd{-1};
};

class UnixSocketClient : UnixSocket {
public:
    UnixSocketClient(const std::string &path);
};

class UnixSocketServer : UnixSocket {
public:
    UnixSocketServer(const std::string &path);
};

}; // namespace unformat
