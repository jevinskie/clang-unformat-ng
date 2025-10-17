#pragma once

#include "common.hpp"

#include <memory>
#include <string>
#include <vector>

#include <clang/Tooling/Core/Replacement.h>
#include <llvm/Support/VirtualFileSystem.h>

namespace unformat {

struct file_buf_t {
    std::string path;
    std::string body;
};

using vfs_t = std::map<std::string, file_buf_t>;

vfs_t construct_vfs(const std::vector<std::string> &fnames);
clang::tooling::Replacements reformat_vfs(const vfs_t &vfs);

}; // namespace unformat
