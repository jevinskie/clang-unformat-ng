#pragma once

#include "common.hpp"

#include <map>
#include <string>
#include <vector>

namespace unformat {
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
    using style_t = std::string;
    style_t style;
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
}; // namespace rpc_cmd
}; // namespace unformat
