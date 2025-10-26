#include "clang-unformat-ng/rpc.hpp"

#include "common-internal.hpp"

#include "clang-unformat-ng/fmt.hpp"
#include "clang-unformat-ng/utils.hpp"

#include <chrono>
#include <stop_token>
#include <thread>

#include <fmt/base.h>

namespace unformat {

RPCServer::RPCServer(const std::string &socket_path)
    : _s{socket_path} {
          // TODO?
      };

static void accept_thread_main(std::stop_token stoken) {
    fmt::print(stderr, "accept_thread_main entry\n");
    while (!stoken.stop_requested()) {
        fmt::print(stderr, "accept_thread_main foo\n");
        std::this_thread::sleep_for(std::chrono::seconds{1});
    }
    fmt::print(stderr, "accept_thread_main exit\n");
    std::this_thread::sleep_for(std::chrono::milliseconds{100});
    fmt::print(stderr, "accept_thread_main exit2\n");
}

std::stop_source RPCServer::run() {
    std::jthread accept_thread(accept_thread_main);
    accept_thread.detach();
    return accept_thread.get_stop_source();
}

RPCServer::~RPCServer() {
    // TODO: std::stop_token?
}

}; // namespace unformat
