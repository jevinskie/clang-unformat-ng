#pragma once

#include "common.hpp"

#include <cstdint>
#include <limits>
#include <span>
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <type_traits>
#include <vector>

namespace unformat {

std::string slurp_file_string(const std::string &path);

class UnixSocket {
public:
    UnixSocket(const std::string &path, bool force);
    ~UnixSocket();

    std::vector<uint8_t> read(size_t size);
    void read(std::span<uint8_t> buf);
    void write(std::span<const uint8_t> buf);

    void bind();
    void connect();
    void listen();
    void accept();
    void shutdown();

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

// UB-ahoy I presume
template <typename sz_t = uint32_t> class LengthPrefixProtocol {
    template <typename T> static T read() {
        constexpr auto sz = sizeof(T);
        static_assert(sz <= std::numeric_limits<sz_t>::max(), "msg sz is >= UINT32_MAX");
        sz_t sz_val{};
        read({static_cast<uint8_t *>(&sz_val), sizeof(sz_t)});
        T res{};
        read({static_cast<uint8_t *>(&res), sizeof(T)});
        return res;
    }
    template <typename T> static void write(const T &value) {
        constexpr auto sz = sizeof(T);
        static_assert(sz <= std::numeric_limits<sz_t>::max(), "msg sz is >= UINT32_MAX");
        const sz_t sz_val{sz};
        write({static_cast<uint8_t *>(std::remove_cv_t<sz_t>(&sz_val)), sizeof(sz_t)});
        write({static_cast<uint8_t *>(&value), sz});
    }
};

}; // namespace unformat
