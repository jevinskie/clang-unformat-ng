#include "clang-unformat-ng/core.hpp"

#include "common-internal.hpp"

#include <memory>
#include <string>
#include <vector>

#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/SourceManager.h>
#include <llvm/Support/FileSystem.h>

#include "clang-unformat-ng/utils.hpp"

namespace unformat {

using namespace llvm;
using namespace clang;

static FileID createInMemoryFile(StringRef FileName, MemoryBufferRef Source, SourceManager &Sources, FileManager &Files,
                                 vfs::InMemoryFileSystem *MemFS) {
    MemFS->addFileNoOwn(FileName, 0, Source);
    auto File = Files.getOptionalFileRef(FileName);
    assert(File && "File not added to MemFS?");
    return Sources.createFileID(*File, SourceLocation(), SrcMgr::C_User);
}

// IntrusiveRefCntPtr<vfs::InMemoryFileSystem> construct_memfs(const std::vector<std::string> &fnames) {
std::unique_ptr<vfs::InMemoryFileSystem> construct_memfs(const std::vector<std::string> &fnames) {
    // auto imvfs = makeIntrusiveRefCnt<vfs::InMemoryFileSystem>();
    // vfs::InMemoryFileSystem imvfs;
    auto imvfs = std::make_unique<vfs::InMemoryFileSystem>();
    FileManager Files(FileSystemOptions(), &*imvfs);
    DiagnosticOptions DiagOpts;
    DiagnosticsEngine Diagnostics(DiagnosticIDs::create(), DiagOpts);
    SourceManager Sources(Diagnostics, Files);
    for (const auto &fname : fnames) {
        const auto fstr = slurp_file_string(fname);
        auto mb         = MemoryBuffer::getMemBufferCopy(fstr, fname);
        const auto fid  = createInMemoryFile(fname, *mb, Sources, Files, &*imvfs);
    }
    return imvfs;
}

clang::tooling::Replacements reformat_vfs(std::unique_ptr<vfs::FileSystem> fs) {
    return {};
}

}; // namespace unformat
