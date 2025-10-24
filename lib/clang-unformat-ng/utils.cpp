#include "clang-unformat-ng/utils.hpp"

#include "common-internal.hpp"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

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

UnixSocket::UnixSocket(const std::string &path, bool force) : _path{path} {
    // setup path in address
    const auto psz     = _path.size();
    const auto psz_nul = psz + 1;
    assert(psz_nul <= sizeof(_addr.sun_path));
    _addr = {.sun_len = static_cast<uint8_t>(offsetof(decltype(_addr), sun_path) + psz_nul), .sun_family = AF_UNIX};
    std::copy_n(_path.cbegin(), std::min(psz, sizeof(_addr.sun_path) - 1), _addr.sun_path);
    _addr.sun_path[psz_nul - 1] = '\0';
};

UnixSocket::~UnixSocket() {
    if (_fd >= 0) {
        ::close(_fd);
    }
}

}; // namespace unformat
