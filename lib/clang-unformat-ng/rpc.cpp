#include "clang-unformat-ng/rpc.hpp"

#include "common-internal.hpp"

#include "clang-unformat-ng/fmt.hpp"
#include "clang-unformat-ng/utils.hpp"

#include <chrono>
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
        std::this_thread::sleep_for(std::chrono::seconds{1});
        fmt::print(stderr, "accept foo\n");
    });
    return accept_thread.get_stop_token();
}

RPCServer::~RPCServer() {
    // TODO: std::stop_token?
}

}; // namespace unformat
