#pragma once

#include <clang-unformat-ng/common.hpp>

#include <clang-unformat-ng/fmt.hpp>
#include <clang-unformat-ng/style.hpp>
#include <clang-unformat-ng/utils.hpp>

#include <map>
#include <memory>
#include <stop_token>
#include <string>
#include <unordered_set>
#include <vector>

#ifndef UNFMTNG_DISABLE_LLVM
#include <clang/Format/Format.h>
#else
#include <clang-unformat-ng/llvm-stubs.hpp>
#endif

#include <rfl.hpp>

namespace unformat {

// enum class rpc_cmd_t {
//     RPC_GETSTYLE,
//     RPC_SETPATHS,
//     RPC_SETSTYLE,
//     RPC_FORMAT
// };

namespace rpc_cmd {

struct get_style_req {
    builtin_style_t style;
};
struct get_style_resp {
    bool ok;
    std::string style_json;
};

struct set_paths_req {
    std::vector<std::string> paths;
};
struct set_paths_resp {
    bool ok;
};

struct set_style_req {
    std::string style_json;
};
struct set_style_resp {
    bool ok;
};

struct format_req {};
struct format_resp_result {
    double score;
};
struct format_resp {
    bool ok;
    std::map<std::string, format_resp_result> results;
};

using request_t  = rfl::TaggedUnion<"rpc_req", get_style_req, set_paths_req, set_style_req, format_req>;
using response_t = rfl::TaggedUnion<"rpc_resp", get_style_resp, set_paths_resp, set_style_resp, format_resp>;

}; // namespace rpc_cmd

class RPCServerConnection {
public:
    RPCServerConnection(int sock);
    RPCServerConnection(RPCServerConnection &other)  = delete;
    RPCServerConnection(RPCServerConnection &&other) = default;
    ~RPCServerConnection();

    std::stop_source run();
    void stop();
    const UnixSocket &socket() const;

    size_t hash() const noexcept;
    auto operator<=>(const RPCServerConnection &o) const {
        return _s <=> o._s;
    }
    bool operator==(const RPCServerConnection &o) const {
        return _s == o._s;
    }

private:
    void rpc_thread_func(std::stop_token stok);

    UnixSocket _s;
    std::jthread _thread;
};
}; // namespace unformat

template <> struct std::hash<unformat::RPCServerConnection> {
    size_t operator()(const unformat::RPCServerConnection &c) const noexcept {
        return c.hash();
    }
};

template <> struct fmt::formatter<unformat::RPCServerConnection> : fmt::formatter<fmt::string_view> {
    constexpr auto format(const unformat::RPCServerConnection &sc, fmt::format_context &ctx) const
        -> fmt::format_context::iterator {
        fmt::format_to(ctx.out(), "RPCServerConnection(.sock = {})", sc.socket());
        return ctx.out();
    }
};

namespace unformat {
class RPCServer {
public:
    RPCServer(const std::string &socket_path);
    RPCServer(RPCServer &other) = delete;
    ~RPCServer();

    std::stop_source run();
    void stop();

private:
    void accept_thread_func(std::stop_token stok);

    UnixSocket _s;
    std::jthread _accept_thread;
    std::unordered_set<std::unique_ptr<RPCServerConnection>> _connections;
};

class RPCClient {
public:
    RPCClient(const std::string &socket_path);
    ~RPCClient();

    clang::format::FormatStyle get_style(builtin_style_t style);

private:
    UnixSocket _s;
};

}; // namespace unformat
