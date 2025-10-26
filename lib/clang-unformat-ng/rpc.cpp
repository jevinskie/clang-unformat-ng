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

void RPCServer::accept_thread_func(std::stop_token stok) {
    std::stop_callback callback(stok, [this] {
        _s.shutdown();
        fmt::print(stderr, "RPCServer::accept_thread_func stop callback\n");
    });

    fmt::print(stderr, "RPCServer::accept_thread_func entry\n");
    while (!stok.stop_requested()) {
        fmt::print(stderr, "RPCServer::accept_thread_func loop\n");
        std::this_thread::sleep_for(std::chrono::seconds{1});
    }
    fmt::print(stderr, "RPCServer::accept_thread_func exit\n");
}

std::stop_source RPCServer::run() {
    _accept_thread = std::jthread{[this](std::stop_token stok) {
        accept_thread_func(stok);
    }};
    _accept_thread.detach();
    return _accept_thread.get_stop_source();
}

RPCServer::~RPCServer() {
    _accept_thread.get_stop_source().request_stop();
}

}; // namespace unformat
