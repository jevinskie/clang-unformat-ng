#include "clang-unformat-ng/utils.hpp"

#include "clang-unformat-ng/fmt.hpp"

#include "common-internal.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <sys/_types/_ssize_t.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <vector>

namespace unformat {

std::string slurp_file_string(const std::string &path) {
    const auto fd = ::open(path.c_str(), O_RDONLY);
    if (fd < 0) {
        ::abort();
    }
    struct stat st;
    if (::fstat(fd, &st)) {
        ::abort();
    }
    const auto sz = static_cast<size_t>(st.st_size);
    if (!sz) {
        ::close(fd);
        ::abort();
    }
    auto res = std::string(sz, '\0');
    if (sz != ::read(fd, res.data(), res.size())) {
        ::abort();
    }
    if (::close(fd)) {
        ::abort();
    }
    return res;
}

UnixSocket::UnixSocket(const std::string &path) : _path{path} {
    // setup path in address
    const auto psz     = _path.size();
    const auto psz_nul = psz + 1;
    assert(psz_nul <= sizeof(_addr.sun_path));
    _addr = {.sun_len = static_cast<uint8_t>(offsetof(decltype(_addr), sun_path) + psz_nul), .sun_family = AF_UNIX};
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
    socklen_t slen{};
    getsockname(_fd, reinterpret_cast<struct sockaddr *>(&_addr), &slen);
    fmt::print(stderr, "from fd: {} slen: {}\n", _fd, slen);
}

UnixSocket::~UnixSocket() {
    if (_fd >= 0) {
        ::close(_fd);
    }
}

void UnixSocket::connect() {
    if (::connect(_fd, reinterpret_cast<struct sockaddr *>(&_addr), _addr.sun_len)) {
        ::perror("connect");
        std::exit(1);
    }
}

void UnixSocket::listen() {
    ::unlink(_path.c_str());
    if (::bind(_fd, reinterpret_cast<struct sockaddr *>(&_addr), sizeof(_addr))) {
        ::perror("listen - bind");
        std::exit(1);
    }
    if (::listen(_fd, 4)) {
        ::perror("listen - listen");
        std::exit(1);
    }
}

void UnixSocket::shutdown() {
    if (::shutdown(_fd, SHUT_RDWR)) {
        ::perror("shutdown");
        std::exit(1);
    }
}

void UnixSocket::read(std::span<uint8_t> buf) {
    if (::recv(_fd, buf.data(), static_cast<ssize_t>(buf.size_bytes()), 0) != buf.size_bytes()) {
        ::perror("recv");
        std::exit(1);
    }
}

std::vector<uint8_t> UnixSocket::read(size_t size) {
    std::vector<uint8_t> buf(size);
    read(buf);
    return buf;
}

void UnixSocket::write(std::span<const uint8_t> buf) {
    if (static_cast<size_t>(::send(_fd, buf.data(), buf.size_bytes(), 0)) != buf.size_bytes()) {
        ::perror("send");
        std::exit(1);
    }
}

size_t UnixSocket::hash() const noexcept {
    return std::hash<decltype(_fd)>{}(_fd);
}

std::tuple<int, sockaddr_un, socklen_t> UnixSocket::accept() {
    socklen_t slen{sizeof(_addr)};
    struct sockaddr_un remote_addr{};
    int conn_fd = ::accept(_fd, reinterpret_cast<struct sockaddr *>(&remote_addr), &slen);
    if (conn_fd < 0) {
        ::perror("accept");
        std::exit(1);
    }
    assert(slen == remote_addr.sun_len);
    fmt::print(stderr, "accept: remote_addr: {} slen: {} ra.sun_len: {}\n", remote_addr, slen, remote_addr.sun_len);
    return {conn_fd, remote_addr, slen};
}

}; // namespace unformat
