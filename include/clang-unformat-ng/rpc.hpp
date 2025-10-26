#pragma once

#include "common.hpp"
#include "style.hpp"
#include "utils.hpp"

#include <map>
#include <stop_token>
#include <string>
#include <vector>

#include <clang/Format/Format.h>

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
    ~RPCServerConnection();

    std::stop_source run();

private:
    void rpc_thread_func(std::stop_token stok);

    UnixSocket _s;
    std::jthread _thread;
};

class RPCServer {
public:
    RPCServer(const std::string &socket_path);
    ~RPCServer();

    std::stop_source run();

private:
    void accept_thread_func(std::stop_token stok);

    UnixSocket _s;
    std::jthread _accept_thread;
    std::vector<RPCServerConnection> _connections;
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
