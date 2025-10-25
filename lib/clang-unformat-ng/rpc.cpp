#include "clang-unformat-ng/rpc.hpp"

#include "common-internal.hpp"

#include "clang-unformat-ng/fmt.hpp"
#include "clang-unformat-ng/utils.hpp"

#include <thread>

#include <fmt/base.h>

namespace unformat {

RPCServer::RPCServer(const std::string &socket_path)
    : _s{socket_path} {
          // TODO?
      };

std::stop_token RPCServer::run() {
    // TODO
    std::jthread accept_thread([] {
        fmt::print("accept foo\n");
    });
    return accept_thread.get_stop_token();
}

RPCServer::~RPCServer() {
    // TODO: std::stop_token?
}

}; // namespace unformat
