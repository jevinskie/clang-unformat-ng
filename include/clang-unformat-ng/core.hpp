#pragma once

#include "common.hpp"

#include <string>
#include <vector>

#include <llvm/Support/VirtualFileSystem.h>

namespace unformat {
llvm::vfs::InMemoryFileSystem construct_memfs(const std::vector<std::string> &fnames);
};
