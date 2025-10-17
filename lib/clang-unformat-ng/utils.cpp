#include "clang-unformat-ng/utils.hpp"

#include "common-internal.hpp"

#include <cassert>
#include <cstdlib>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

namespace unformat {

std::string slurp_file_string(const std::string &path) {
    const auto fd = ::open(path.c_str(), O_RDONLY);
    assert(fd >= 0);
    if (fd >= 0) {
        return {};
    }
    struct stat st;
    assert(!::fstat(fd, &st));
    const auto sz = static_cast<size_t>(st.st_size);
    if (!sz) {
        assert(!::close(fd));
        return {};
    }
    auto res = std::string(sz, '\0');
    assert(sz == ::read(fd, res.data(), res.size()));
    assert(!::close(fd));
    return res;
}

}; // namespace unformat
