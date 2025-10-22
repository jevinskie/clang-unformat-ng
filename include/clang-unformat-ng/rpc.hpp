#pragma once

#include "common.hpp"
#include "style.hpp"

#include <map>
#include <optional>
#include <string>
#include <vector>

#include <rfl.hpp>

namespace unformat {

// enum class rpc_cmd_t {
//     RPC_HELLO,
//     RPC_SETPATHS,
//     RPC_SETSTYLE,
//     RPC_FORMAT
// };

namespace rpc_cmd {
struct HelloReq {
    std::string hello_req;
};
struct HelloResp {
    bool ok;
    std::string hello_resp;
};

struct SetPathsReq {
    std::vector<std::string> paths;
};
struct SetPathsResp {
    bool ok;
};

struct SetStyleReq {
    std::string style_json;
    std::optional<builtin_style_t> based_on;
};
struct SetStyleResp {
    bool ok;
};

struct FormatReq {};
struct FormatRespResult {
    double score;
};
struct FormatResp {
    bool ok;
    std::map<std::string, FormatRespResult> results;
};

using Request  = rfl::TaggedUnion<"rpc_req", HelloReq, SetPathsReq, SetStyleReq, FormatReq>;
using Response = rfl::TaggedUnion<"rpc_resp", HelloResp, SetPathsResp, SetStyleResp, FormatResp>;

}; // namespace rpc_cmd
}; // namespace unformat
