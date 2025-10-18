#include "clang-unformat-ng/core.hpp"

#include "common-internal.hpp"

#include "clang-unformat-ng/style.hpp"
#include "clang-unformat-ng/utils.hpp"

#include "clang/Tooling/Core/Replacement.h"

#include <stdlib.h>
#include <string>
#include <vector>

#include <clang/Basic/FileManager.h>
#include <clang/Basic/SourceLocation.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Format/Format.h>
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

// for my reference
/// Reformats the given \p Ranges in \p Code.
///
/// Each range is extended on either end to its next bigger logic unit, i.e.
/// everything that might influence its formatting or might be influenced by its
/// formatting.
///
/// Returns the ``Replacements`` necessary to make all \p Ranges comply with
/// \p Style.
///
/// If ``Status`` is non-null, its value will be populated with the status of
/// this formatting attempt. See \c FormattingAttemptStatus.
tooling::Replacements reformat(const format::FormatStyle &Style, StringRef Code, ArrayRef<tooling::Range> Ranges,
                               StringRef FileName = "<stdin>", format::FormattingAttemptStatus *Status = nullptr);

static clang::tooling::Replacements reformat_file(const file_buf_t &fbuf) {
    // run libformat reformat()
    const auto &src  = fbuf.body;
    const auto &path = fbuf.path;

    const auto style = format::getLLVMStyle();

    const tooling::Range file_ranges[] = {tooling::Range{0, static_cast<unsigned int>(src.size())}};

    format::FormattingAttemptStatus fmt_status;
    auto res = clang::format::reformat(style, src, file_ranges, path, &fmt_status);
    if (!fmt_status.FormatComplete) {
        fmt::print("couldn't complete format (line {}) for fbuf for \"{}\"\n", fmt_status.Line, fbuf.path);
        abort();
    }
    return res;
}

file_replacements_t reformat_file_buf(const file_buf_t &fbuf) {
    return {.path = fbuf.path, .replacements = reformat_file(fbuf)};
}

vfs_replacements_t reformat_vfs(const vfs_t &vfs) {
    vfs_replacements_t res;
    for (const auto &[path, src] : vfs) {
        res.insert_or_assign(path, reformat_file_buf(vfs.at(path)));
    }
    get_style(builtin_style_t::none);
    return res;
}

}; // namespace unformat
