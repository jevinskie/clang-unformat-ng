#pragma once

#include "common.hpp"

#include <memory>
#include <string>
#include <vector>

#include <clang/Tooling/Core/Replacement.h>
#include <llvm/Support/VirtualFileSystem.h>

namespace unformat {
std::unique_ptr<llvm::vfs::InMemoryFileSystem> construct_memfs(const std::vector<std::string> &fnames);
clang::tooling::Replacements reformat_vfs(std::unique_ptr<llvm::vfs::FileSystem> vfs);
}; // namespace unformat
