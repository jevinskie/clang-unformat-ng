#include "clang-unformat-ng/utils.hpp"

#include "common-internal.hpp"

#include <sys/fcntl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#include <boost/asio/connect.hpp>
#include <boost/asio/local/stream_protocol.hpp>

namespace net = boost::asio;
using unix_fd = boost::asio::local::stream_protocol;

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
    struct sockaddr_un addr;
    _fd = -1;
}

}; // namespace unformat
