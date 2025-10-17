#include "clang-unformat-ng/utils.hpp"

#include "common-internal.hpp"

#include <_abort.h>
#include <cassert>
#include <cstdlib>
#include <sys/fcntl.h>
#include <sys/stat.h>
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

}; // namespace unformat
