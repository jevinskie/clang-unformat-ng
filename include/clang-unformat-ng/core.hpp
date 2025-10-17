#pragma once

#include "common.hpp"

#include <map>
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

struct file_replacements_t {
    std::string path;
    clang::tooling::Replacements replacements;
};

using vfs_t              = std::map<std::string, file_buf_t>;
using vfs_replacements_t = std::map<std::string, file_replacements_t>;

vfs_t construct_vfs(const std::vector<std::string> &fnames);
file_replacements_t reformat_file_buf(const file_buf_t &fbuf);
vfs_replacements_t reformat_vfs(const vfs_t &vfs);

}; // namespace unformat
