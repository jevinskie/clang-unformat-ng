#pragma once

#include "common.hpp"

#include <string>
#include <vector>

#include <clang/Tooling/Core/Replacement.h>
#include <llvm/Support/VirtualFileSystem.h>

namespace unformat {
llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> construct_memfs(const std::vector<std::string> &fnames);
clang::tooling::Replacements reformat_vfs(llvm::vfs::FileSystem &fs);
}; // namespace unformat
