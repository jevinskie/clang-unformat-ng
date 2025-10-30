#include "clang-unformat-ng/rpc.hpp"

#include "common-internal.hpp"

#include "clang-unformat-ng/fmt.hpp"
#include "clang-unformat-ng/utils.hpp"

#include <chrono>
#include <functional>
#include <stop_token>
#include <sys/socket.h>
#include <sys/un.h>
#include <thread>

#include <fmt/base.h>

namespace unformat {

/// RPCServerConnection
RPCServerConnection::RPCServerConnection(int sock) : _s{sock} {};

void RPCServerConnection::rpc_thread_func(std::stop_token stok) {
    std::stop_callback callback(stok, [this] {
        fmt::print(stderr, "RPCServerConnection::rpc_thread_func stop callback\n");
        _s.shutdown();
    });

    fmt::print(stderr, "RPCServerConnection::rpc_thread_func entry\n");
    while (!stok.stop_requested()) {
        fmt::print(stderr, "RPCServerConnection::rpc_thread_func loop\n");
        std::this_thread::sleep_for(std::chrono::seconds{1});
    }
    fmt::print(stderr, "RPCServerConnection::rpc_thread_func exit\n");
}

std::stop_source RPCServerConnection::run() {
    _thread = std::jthread{[this](std::stop_token stok) {
        rpc_thread_func(stok);
    }};
    _thread.detach();
    return _thread.get_stop_source();
}

RPCServerConnection::~RPCServerConnection() {
    _thread.get_stop_source().request_stop();
}

size_t RPCServerConnection::hash() const noexcept {
    return std::hash<UnixSocket>{}(_s);
}

/// RPCServer
RPCServer::RPCServer(const std::string &socket_path) : _s{socket_path} {};

void RPCServer::accept_thread_func(std::stop_token stok) {
    std::stop_callback callback(stok, [this] {
        fmt::print(stderr, "RPCServer::accept_thread_func stop callback\n");
        // _s.shutdown();
    });

    fmt::print(stderr, "RPCServer::accept_thread_func entry\n");
    _s.listen();
    while (!stok.stop_requested()) {
        fmt::print(stderr, "RPCServer::accept_thread_func loop\n");
        auto [new_sock, remote_addr, remote_addr_len] = _s.accept();
        fmt::print(stderr, "accept: new_sock: {} raddr: {} raddr_sz: {}\n", new_sock, remote_addr, remote_addr_len);
        RPCServerConnection conn{new_sock};
        fmt::print(stderr, "RPCServer::accept_thread_func loop RPCServerConnection created\n");
        std::stop_callback conn_cb(stok, [&conn, this] {
            fmt::print(stderr, "RPCServer::accept_thread_func conn_cb callback\n");
            _connections.erase(conn);
        });
        conn.run();
        _connections.emplace(std::move(conn));
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
