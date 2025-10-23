#pragma once

#include "common.hpp"
#include "style.hpp"
#include "utils.hpp"

#include <map>
#include <string>
#include <vector>

#include <clang/Format/Format.h>

#include <boost/asio/connect.hpp>
#include <boost/asio/local/stream_protocol.hpp>
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

using namespace boost::asio;
namespace local = boost::asio::local;
typedef local::stream_protocol sp;

class RPCServer {
public:
    using cb_t = bool (*)(RPCServer &server);
    RPCServer(const std::string &socket_path);
    void run(cb_t cb_func);

private:
};

class RPCClient {
public:
    RPCClient(const std::string &socket_path);
    clang::format::FormatStyle get_style(builtin_style_t style);

private:
};

}; // namespace unformat
