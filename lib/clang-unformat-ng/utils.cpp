#include "clang-unformat-ng/utils.hpp"

#include "common-internal.hpp"

#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

namespace unformat {

std::vector<uint8_t> slurp_file_bytes(const std::string &path) {
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
    std::vector<uint8_t> res;
    res.reserve(sz);
    assert(sz == ::read(fd, res.data(), res.size()));
    assert(!::close(fd));
    return res;
}

std::string slurp_file_string(const std::string &path) {
    const auto bytes_res = slurp_file_bytes(path);
    return std::string(bytes_res.cbegin(), bytes_res.cend());
}

}; // namespace unformat
