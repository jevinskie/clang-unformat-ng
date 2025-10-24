#pragma once

#include "common.hpp"

#include <cstdint>
#include <limits>
#include <span>
#include <string>
#include <sys/un.h>
#include <type_traits>
#include <vector>

namespace unformat {

std::string slurp_file_string(const std::string &path);

class UnixSocket {
    // o yah well ur butt is Undefined Behavior
public:
    UnixSocket(const std::string &path);
    ~UnixSocket();

    std::vector<uint8_t> read_raw(size_t size);
    void read_raw(std::vector<uint8_t> &buf);
    void read_raw(std::span<uint8_t> buf);
    std::vector<uint8_t> read(size_t size);
    void read(std::span<uint8_t> buf);
    template <typename T> T read() {
        constexpr auto sz = sizeof(T);
        static_assert(sz <= std::numeric_limits<T>::max(), "msg sz is >= UINT32_MAX");
        uint32_t sz_u32{};
        read_raw({reinterpret_cast<uint8_t *>(&sz_u32), sizeof(uint32_t)});
        T res{};
        read_raw({reinterpret_cast<uint8_t *>(&res), sizeof(T)});
        return res;
    }

    void write_raw(std::span<const uint8_t> buf);
    void write(std::span<const uint8_t> buf);
    template <typename T> void write(const T &value) {
        constexpr auto sz = sizeof(T);
        static_assert(sz <= std::numeric_limits<T>::max(), "msg sz is >= UINT32_MAX");
        const uint32_t sz_u32{sz};
        write_raw({static_cast<uint8_t *>(std::remove_cv_t<uint32_t>(&sz_u32)), sizeof(uint32_t)});
        write_raw({static_cast<uint8_t *>(&value), sz});
    }

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
