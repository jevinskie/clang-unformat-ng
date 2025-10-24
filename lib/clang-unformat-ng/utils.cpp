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

UnixSocket::UnixSocket(const std::string &path) : _path{path} {
    const auto path_w_nul_sz = _path.size() + 1;
    assert(path_w_nul_sz <= sizeof(_addr.sun_path));
    _addr = {.sun_len    = static_cast<uint8_t>(offsetof(decltype(_addr), sun_path) + path_w_nul_sz),
             .sun_family = AF_UNIX};
    std::copy_n(_path.cbegin(), std::min(path_w_nul_sz, sizeof(_addr.sun_path) - 1), _addr.sun_path);
    _addr.sun_path[path_w_nul_sz - 1] = '\0';
};

}; // namespace unformat
