#pragma once

#include "common.hpp"

#include "fmt.hpp"

#include <cstdint>
#include <limits>
#include <span>
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <tuple>
#include <type_traits>
#include <vector>

namespace unformat {

std::string slurp_file_string(const std::string &path);

class UnixSocket {
public:
    UnixSocket(const std::string &path);
    UnixSocket(int sock);
    ~UnixSocket();

    std::vector<uint8_t> read(size_t size);
    void read(std::span<uint8_t> buf);
    void write(std::span<const uint8_t> buf);
    template <POD T> T read() {
        T res{};
        read({static_cast<uint8_t *>(&res), sizeof(T)});
        return res;
    }
    template <POD T> void write(const T &value) {
        write({static_cast<uint8_t *>(&value), sizeof(T)});
    }

    void connect();
    void listen();
    std::tuple<int, sockaddr_un, socklen_t> accept();
    void shutdown();

    const std::string &path() const noexcept {
        return _path;
    }
    const struct sockaddr_un &addr() const noexcept {
        return _addr;
    }
    int fd() const noexcept {
        return _fd;
    }
    size_t hash() const noexcept;
    auto operator<=>(const UnixSocket &o) const noexcept {
        return _fd <=> o._fd;
    }
    bool operator==(const UnixSocket &o) const noexcept {
        return _fd == o._fd;
    }

private:
    const std::string _path;
    struct sockaddr_un _addr;
    int _fd{-1};
};
}; // namespace unformat

template <> struct std::hash<unformat::UnixSocket> {
    size_t operator()(const unformat::UnixSocket &s) const noexcept {
        return s.hash();
    }
};

template <> struct fmt::formatter<unformat::UnixSocket> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const unformat::UnixSocket &s, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "UnixSock{{ .path = {} .fd = {}, .addr = {}}}", s.path(), s.fd(), s.addr());
        return ctx.out();
    }
};

namespace unformat {

class UnixSocketClient : UnixSocket {
public:
    UnixSocketClient(const std::string &path);
};

class UnixSocketServer : UnixSocket {
public:
    UnixSocketServer(const std::string &path);
};

template <typename T>
concept read_func_t = requires(T rf) {
    { rf(std::span<uint8_t>{}) } -> std::same_as<void>;
};

template <typename T>
concept write_func_t = requires(T wf) {
    { wf(std::span<const uint8_t>{}) } -> std::same_as<void>;
};

template <typename T>
concept ReaderWriter = requires(T t) {
    { t.read(std::span<uint8_t>{}) } -> std::same_as<void>;
    { t.write(std::span<const uint8_t>{}) } -> std::same_as<void>;
};

// UB-ahoy I presume
template <ReaderWriter rw_t, typename sz_t = uint32_t> class LengthPrefixProtocol {
    static std::vector<uint8_t> read(rw_t &rw) {
        const auto sz_val = rw.template read<sz_t>();
        return rw.read(sz_val);
    }
    template <POD T> static T read(rw_t &rw) {
        constexpr auto sz = sizeof(T);
        static_assert(sz <= std::numeric_limits<sz_t>::max(), "msg sz is >= UINT32_MAX");
        const auto sz_val = rw.template read<sz_t>();
        assert(sz_val == sz);
        return rw.template read<T>();
    }
    template <POD T> static void write(rw_t &rw, const T &value) {
        constexpr auto sz = sizeof(T);
        static_assert(sz <= std::numeric_limits<sz_t>::max(), "msg sz is >= UINT32_MAX");
        rw.template write<sz_t>(sz);
        rw.template write<T>(value);
    }
};

}; // namespace unformat
