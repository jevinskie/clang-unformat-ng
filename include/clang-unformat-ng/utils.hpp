#pragma once

#include <clang-unformat-ng/common.hpp>

#include <clang-unformat-ng/fmt.hpp>

#include <cstdint>
#include <limits>
#include <span>
#include <string>
#include <sys/socket.h>
#include <sys/un.h>
#include <vector>

namespace unformat {

std::string slurp_file_string(const std::string &path);

class UnixSocket {
public:
    struct accept_res_t {
        int socket;
        struct sockaddr_un addr;
        socklen_t addr_len;
    };
    UnixSocket(const std::string &path);
    UnixSocket(int sock);
    UnixSocket(UnixSocket &other)  = delete;
    UnixSocket(UnixSocket &&other) = default;
    ~UnixSocket();

    std::vector<uint8_t> read(size_t size);
    void read(std::span<uint8_t> buf);
    void write(std::span<const uint8_t> buf);
    template <POD T> T read() {
        T res{};
        read({reinterpret_cast<uint8_t *>(&res), sizeof(T)});
        return res;
    }
    template <POD T> void write(const T &value) {
        write({reinterpret_cast<uint8_t const *>(&value), sizeof(T)});
    }

    void connect();
    void listen();
    accept_res_t accept();
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
template <typename sz_t = uint32_t> struct LengthPrefixProtocol {
    static std::vector<uint8_t> read(ReaderWriter auto &rw) {
        const auto sz_val = rw.template read<sz_t>();
        return rw.read(sz_val);
    }
    static void write(ReaderWriter auto &rw, std::span<const uint8_t> buf) {
        rw.template write<sz_t>(buf.size_bytes());
        rw.write(buf);
    }
    template <POD T> static T read(ReaderWriter auto &rw) {
        constexpr auto sz = sizeof(T);
        static_assert(sz <= std::numeric_limits<sz_t>::max(), "msg sz is >= UINT32_MAX");
        const auto sz_val = rw.template read<sz_t>();
        assert(sz_val == sz);
        return rw.template read<T>();
    }
    template <POD T> static void write(ReaderWriter auto &rw, const T &value) {
        constexpr auto sz = sizeof(T);
        static_assert(sz <= std::numeric_limits<sz_t>::max(), "msg sz is >= UINT32_MAX");
        rw.template write<sz_t>(sz);
        rw.template write<T>(value);
    }
};

}; // namespace unformat
