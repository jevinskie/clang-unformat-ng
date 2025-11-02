#pragma once

#include <clang-unformat-ng/common.hpp>

#include <clang-unformat-ng/fmt.hpp>
#include <clang-unformat-ng/style.hpp>

#include <map>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

#ifndef UNFMTNG_DISABLE_LLVM
#include <clang/Tooling/Core/Replacement.h>
#include <llvm/Support/VirtualFileSystem.h>
#else
#include <clang-unformat-ng/llvm-stubs.hpp>
#endif

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
file_replacements_t reformat_file_buf(const file_buf_t &fbuf, builtin_style_t style);
vfs_replacements_t reformat_vfs(const vfs_t &vfs, builtin_style_t style);

} // namespace unformat

template <> struct fmt::formatter<unformat::file_buf_t> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const unformat::file_buf_t &b, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "FBuf{{.path = \"{}\", .body = \"{:.24s}\"}}", b.path, b.body);
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

template <> struct fmt::formatter<unformat::vfs_t::const_iterator> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const unformat::vfs_t::const_iterator &i, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "vfs_item_t{{.path = \"{}\", .fbuf = \"{}\"}}", i->first, i->second);
        return ctx.out();
    }
};

template <> struct fmt::formatter<unformat::vfs_t> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const unformat::vfs_t &v, fmt::format_context &ctx) const -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "vfs_t{{{}}}", fmt::join(v, ", "));
        return ctx.out();
    }
};
