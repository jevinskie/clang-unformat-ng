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

std::stop_source RPCServer::run() {
    // TODO
    std::jthread accept_thread([] {
        fmt::print(stderr, "accept_thread entry\n");
        for (int i = 0; i < 10; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds{1});
            fmt::print(stderr, "accept foo\n");
        }
    });
    accept_thread.detach();
    return accept_thread.get_stop_source();
}

RPCServer::~RPCServer() {
    // TODO: std::stop_token?
}

}; // namespace unformat
