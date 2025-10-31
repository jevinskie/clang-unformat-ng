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
        // std::this_thread::sleep_for(std::chrono::seconds{1});
        // auto buf = _s.read(4);
        // auto buf = LengthPrefixProtocol<UnixSocket>::read(_s);
        auto buf = LengthPrefixProtocol<UnixSocket>::read(_s);
        fmt::print(stderr, "buf sz: {}\n", buf.size());
        fmt::print(stderr, "buf cstr: {:s}\n", reinterpret_cast<char *>(buf.data()));
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
    return _s.hash();
}

/// RPCServer
RPCServer::RPCServer(const std::string &socket_path) : _s{socket_path} {};

void RPCServer::accept_thread_func(std::stop_token stok) {
    // std::stop_callback callback(stok, [this] {
    //     fmt::print(stderr, "RPCServer::accept_thread_func stop callback\n");
    //     // _s.shutdown();
    // });

    fmt::print(stderr, "RPCServer::accept_thread_func entry\n");
    _s.listen();
    while (!stok.stop_requested()) {
        fmt::print(stderr, "RPCServer::accept_thread_func loop\n");
        auto [new_sock, remote_addr, remote_addr_len] = _s.accept();
        fmt::print(stderr, "accept: new_sock: {} raddr: {} raddr_sz: {}\n", new_sock, remote_addr, remote_addr_len);
        RPCServerConnection conn{new_sock};
        fmt::print(stderr, "RPCServer::accept_thread_func loop RPCServerConnection created\n");
        auto conn_stok = conn.run();
        std::stop_callback conn_cb(conn_stok.get_token(), [this] {
            fmt::print(stderr, "RPCServer::accept_thread_func conn_cb callback\n");
            // _connections.erase(conn);
        });
        _connections.emplace(RPCServerConnection{new_sock});

        // auto conn_it = _connections.emplace(RPCServerConnection{new_sock});
        // conn_it.first->run();
        // _connections.emplace(RPCServerConnection{new_sock});
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
