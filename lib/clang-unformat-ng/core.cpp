#include "clang-unformat-ng/core.hpp"

#include "common-internal.hpp"

#include "clang-unformat-ng/utils.hpp"

#include <string>
#include <vector>

#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/SourceManager.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/VirtualFileSystem.h>

namespace unformat {

using namespace llvm;
using namespace clang;

vfs_t construct_vfs(const std::vector<std::string> &fnames) {
    vfs_t fs;
    for (const auto &fname : fnames) {
        const auto src = slurp_file_string(fname);
        fs.insert_or_assign(fname, file_buf_t{fname, src});
    }
    return fs;
}

clang::tooling::Replacements reformat_vfs(const vfs_t &vfs) {
    return {};
}

}; // namespace unformat
