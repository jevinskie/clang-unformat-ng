#pragma once

#include "common.hpp"

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

#include <clang/Tooling/Core/Replacement.h>

static_assert(std::ranges::range<clang::tooling::Replacements>);

template <> struct fmt::formatter<clang::tooling::Replacement> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const clang::tooling::Replacement &r, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "R1 {{ ");
        fmt::format_to(ctx.out(), "{}", r.toString());
        fmt::format_to(ctx.out(), " }}");
        return ctx.out();
    }
};

template <> struct fmt::formatter<clang::tooling::Replacements> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const clang::tooling::Replacements &rs, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "Rn {{ ");
        fmt::format_to(ctx.out(), "{}", fmt::join(rs, " "));
        fmt::format_to(ctx.out(), " }}");
        return ctx.out();
    }
};
