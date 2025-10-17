#include "clang-unformat-ng/core.hpp"

#include "common-internal.hpp"

#include <string>
#include <vector>

#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/SourceManager.h>
#include <llvm/Support/FileSystem.h>

namespace unformat {

using namespace llvm;
using namespace clang;

static FileID createInMemoryFile(StringRef FileName, MemoryBufferRef Source, SourceManager &Sources, FileManager &Files,
                                 llvm::vfs::InMemoryFileSystem *MemFS) {
    MemFS->addFileNoOwn(FileName, 0, Source);
    auto File = Files.getOptionalFileRef(FileName);
    assert(File && "File not added to MemFS?");
    return Sources.createFileID(*File, SourceLocation(), SrcMgr::C_User);
}

llvm::vfs::InMemoryFileSystem construct_memfs(const std::vector<std::string> &fnames) {
    return {};
}

}; // namespace unformat
