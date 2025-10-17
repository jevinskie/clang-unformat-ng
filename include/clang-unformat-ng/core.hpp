#pragma once

#include "common.hpp"

#include "fmt.hpp"

#include <map>
#include <string>
#include <vector>

#include <clang/Tooling/Core/Replacement.h>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>
#include <fmt/std.h>
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

using vfs_t                  = std::map<std::string, file_buf_t>;
using vfs_key_t              = vfs_t::key_type;
using vfs_val_t              = vfs_t::value_type;
using vfs_replacements_t     = std::map<std::string, file_replacements_t>;
using vfs_replacements_key_t = vfs_replacements_t::key_type;
using vfs_replacements_val_t = vfs_replacements_t::value_type;

vfs_t construct_vfs(const std::vector<std::string> &fnames);
file_replacements_t reformat_file_buf(const file_buf_t &fbuf);
vfs_replacements_t reformat_vfs(const vfs_t &vfs);

}; // namespace unformat

template <> struct fmt::formatter<unformat::file_buf_t> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const unformat::file_buf_t &b, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "FBuf{{.path = \"{}\", .body = \"{:24s}\"}}", b.path, b.body);
        return ctx.out();
    }
};

template <> struct fmt::formatter<unformat::file_replacements_t> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const unformat::file_replacements_t &r, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "FRep{{.path = \"{}\", .repl = {}}}", r.path, fmt::join(r.replacements, ", "));
        return ctx.out();
    }
};

template <> struct fmt::formatter<unformat::vfs_t> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const unformat::vfs_t &v, fmt::format_context &ctx) const -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "vfs_t{{{}}}", fmt::join({t.cbegin(), t.cend()}, ", "));
        return ctx.out();
    }
};
