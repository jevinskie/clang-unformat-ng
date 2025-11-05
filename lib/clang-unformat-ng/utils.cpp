#include "clang-unformat-ng/utils.hpp"

#include "common-internal.hpp"

#include <clang-unformat-ng/fmt.hpp>

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <vector>

namespace unformat {

result<std::string> slurp_file_string(const std::string &path) {
    const auto fd = ::open(path.c_str(), O_RDONLY);
    if (fd < 0) {
        return leaf::new_error(slurp_et::open, leaf::e_errno{errno});
    }
    struct stat st;
    if (::fstat(fd, &st)) {
        return leaf::new_error(slurp_et::stat, leaf::e_errno{errno});
    }
    const auto sz = static_cast<size_t>(st.st_size);
    if (!sz) {
        if (::close(fd)) {
            return leaf::new_error(slurp_et::close, leaf::e_errno{errno});
        }
        return {};
    }
    auto res = std::string(sz, '\0');
    if (static_cast<ssize_t>(sz) != ::read(fd, res.data(), res.size())) {
        return leaf::new_error(slurp_et::read, leaf::e_errno{errno});
    }
    if (::close(fd)) {
        return leaf::new_error(slurp_et::close, leaf::e_errno{errno});
    }
    return res;
}

UnixSocket::UnixSocket(const std::string &path) : _path{path} {
    fmt::print(stderr, "UnixSocket(\"{}\")\n", _path);

    // setup path in address
    const auto psz     = _path.size();
    const auto psz_nul = psz + 1;
    assert(psz_nul <= sizeof(_addr.sun_path));
    _addr = {.sun_family = AF_UNIX};
    std::copy_n(_path.cbegin(), std::min(psz, sizeof(_addr.sun_path) - 1), _addr.sun_path);
    _addr.sun_path[psz_nul - 1] = '\0';
    fmt::print(stderr, "accept: remote_addr: {}\n", _addr);

    _fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (_fd < 0) {
        ::perror("UnixSocket() socket");
        std::exit(1);
    }
}

UnixSocket::UnixSocket(int sock) : _fd{sock} {
    fmt::print(stderr, "UnixSocket({})\n", _fd);
    socklen_t slen{};
    if (getsockname(_fd, reinterpret_cast<struct sockaddr *>(&_addr), &slen)) {
        ::perror("UnixSocket() getsockname");
        std::exit(1);
    }
    fmt::print(stderr, "UnixSocket() from fd: {} slen: {}\n", _fd, slen);
}

UnixSocket::~UnixSocket() {
    fmt::print(stderr, "~UnixSocket({})\n", _fd);
    if (_fd >= 0) {
        ::close(_fd);
    }
}

result<void> UnixSocket::connect() {
    if (::connect(_fd, reinterpret_cast<struct sockaddr *>(&_addr), sizeof(_addr))) {
        ::perror("connect");
        std::exit(1);
    }
    return {};
}

result<void> UnixSocket::listen() {
    ::unlink(_path.c_str());
    if (::bind(_fd, reinterpret_cast<struct sockaddr *>(&_addr), sizeof(_addr))) {
        ::perror("listen - bind");
        std::exit(1);
    }
    if (::listen(_fd, 4)) {
        ::perror("listen - listen");
        std::exit(1);
    }
    return {};
}

result<void> UnixSocket::shutdown() {
    if (::shutdown(_fd, SHUT_RDWR)) {
        return leaf::new_error(sock_et::shutdown, leaf::e_errno{errno});
    }
    return {};
}

result<void> UnixSocket::read(std::span<uint8_t> buf) {
    if (::recv(_fd, buf.data(), static_cast<ssize_t>(buf.size_bytes()), 0) != static_cast<ssize_t>(buf.size_bytes())) {
        return leaf::new_error(sock_et::recv, leaf::e_errno{errno});
    }
    return {};
}

result<std::vector<uint8_t>> UnixSocket::read(size_t size) {
    std::vector<uint8_t> buf(size);
    BOOST_LEAF_CHECK(read(buf));
    return buf;
}

result<void> UnixSocket::write(std::span<const uint8_t> buf) {
    if (static_cast<size_t>(::send(_fd, buf.data(), buf.size_bytes(), 0)) != buf.size_bytes()) {
        return leaf::new_error(sock_et::send, leaf::e_errno{errno});
    }
    return {};
}

result<std::string> UnixSocket::read_str(size_t size) {
    std::string buf(size, '\0');
    BOOST_LEAF_CHECK(read({reinterpret_cast<uint8_t *>(buf.data()), buf.size()}));
    return buf;
}

result<void> UnixSocket::write_str(const std::string_view str) {
    return write({reinterpret_cast<const uint8_t *>(str.data()), str.size()});
}

size_t UnixSocket::hash() const noexcept {
    return std::hash<decltype(_fd)>{}(_fd);
}

result<UnixSocket::accept_res_t> UnixSocket::accept() {
    struct sockaddr_un remote_addr{};
    socklen_t slen{sizeof(remote_addr)};
    int conn_fd = ::accept(_fd, reinterpret_cast<struct sockaddr *>(&remote_addr), &slen);
    if (conn_fd < 0) {
        ::perror("accept");
        std::exit(1);
    }
    fmt::print(stderr, "accept: remote_addr: {} slen: {} SUN_LEN: {}\n", remote_addr, slen, SUN_LEN(&remote_addr));
    return {conn_fd, remote_addr, slen};
}

} // namespace unformat
