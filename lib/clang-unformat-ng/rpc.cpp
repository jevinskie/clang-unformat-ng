#include "clang-unformat-ng/rpc.hpp"

#include "common-internal.hpp"

#include "clang-unformat-ng/fmt.hpp"
#include "clang-unformat-ng/utils.hpp"

#include <chrono>
#include <stop_token>
#include <thread>

#include <fmt/base.h>

namespace unformat {

RPCServer::RPCServer(const std::string &socket_path) : _s{socket_path} {};

std::stop_source RPCServer::run() {
    std::jthread accept_thread{[this](std::stop_token stok) {
        std::stop_callback callback(stok, [this] {
            // _s.shutdown();
            fmt::print(stderr, "RPCServer::run accept_thread stop callback\n");
        });

        fmt::print(stderr, "accept_thread_main entry\n");
        while (!stok.stop_requested()) {
            fmt::print(stderr, "accept_thread_main loop\n");
            std::this_thread::sleep_for(std::chrono::seconds{1});
        }
        fmt::print(stderr, "accept_thread_main exit\n");
    }};
    accept_thread.detach();
    _accept_stop_src = accept_thread.get_stop_source();
    return accept_thread.get_stop_source();
}

RPCServer::~RPCServer() {
    _accept_stop_src.request_stop();
}

}; // namespace unformat
