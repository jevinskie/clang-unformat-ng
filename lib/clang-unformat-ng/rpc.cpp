#include "clang-unformat-ng/rpc.hpp"

#include "common-internal.hpp"

#include "clang-unformat-ng/fmt.hpp"
#include "clang-unformat-ng/utils.hpp"

#include <chrono>
#include <functional>
#include <memory>
#include <stop_token>
#include <sys/socket.h>
#include <sys/un.h>
#include <thread>

#include <fmt/base.h>

using namespace std::literals;

namespace unformat {

/// RPCServerConnection
RPCServerConnection::RPCServerConnection(int sock) : _s{sock} {
    fmt::print(stderr, "RPCServerConnection({})\n", _s);
}

void RPCServerConnection::rpc_thread_func(std::stop_token stok) {
    std::stop_callback callback(stok, [this] {
        fmt::print(stderr, "RPCServerConnection::rpc_thread_func stop callback\n");
        _s.shutdown();
    });

    fmt::print(stderr, "RPCServerConnection::rpc_thread_func entry\n");
    while (!stok.stop_requested()) {
        fmt::print(stderr, "RPCServerConnection::rpc_thread_func loop\n");
        auto in_msg_buf = LengthPrefixProtocol<>::read(_s);
        fmt::print(stderr, "in_msg_buf sz: {}\n", in_msg_buf.size());
        fmt::print(stderr, "in_msg_buf cstr: {:s}\n", reinterpret_cast<char *>(in_msg_buf.data()));
        const auto resp = "{\"resp\": 200}"s;
        LengthPrefixProtocol<>::write(_s, {reinterpret_cast<const uint8_t *>(resp.data()), resp.size()});
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

void RPCServerConnection::stop() {
    fmt::print(stderr, "RPCServerConnection::stop()\n");
    _thread.request_stop();
}

const UnixSocket &RPCServerConnection::socket() const {
    return _s;
};

RPCServerConnection::~RPCServerConnection() {
    fmt::print(stderr, "~RPCServerConnection({})\n", _s);
    stop();
}

size_t RPCServerConnection::hash() const noexcept {
    return _s.hash();
}

/// RPCServer
RPCServer::RPCServer(const std::string &socket_path) : _s{socket_path} {
    fmt::print(stderr, "RPCServer({})\n", _s);
}

void RPCServer::accept_thread_func(std::stop_token stok) {
    fmt::print(stderr, "RPCServer::accept_thread_func entry\n");

    std::stop_callback callback(stok, [this] {
        fmt::print(stderr, "RPCServer::accept_thread_func stop callback\n");
        // _s.shutdown();
    });

    _s.listen();
    while (!stok.stop_requested()) {
        fmt::print(stderr, "RPCServer::accept_thread_func loop\n");
        auto [new_sock, remote_addr, remote_addr_len] = _s.accept();
        fmt::print(stderr, "accept: new_sock: {} raddr: {} raddr_sz: {}\n", new_sock, remote_addr, remote_addr_len);
        auto conn = std::make_unique<RPCServerConnection>(new_sock);
        fmt::print(stderr, "RPCServer::accept_thread_func loop RPCServerConnection created\n");
        // auto conn_stok = conn.run();
        // std::stop_callback conn_cb(conn_stok.get_token(), [this] {
        //     fmt::print(stderr, "RPCServer::accept_thread_func conn_cb callback\n");
        //     // _connections.erase(conn);
        // });
        auto [it, added] = _connections.emplace(std::move(conn));
        (*it)->run();
        assert(added);
        auto it2  = _connections.find(*it);
        auto &obj = *it2;
        // fmt::print(stderr, "_conn.emp() => foo: {} bar: {}\n", *foo, bar);

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

void RPCServer::stop() {
    fmt::print(stderr, "RPCServer::stop()\n");
    _accept_thread.request_stop();
    for (auto &conn : _connections) {
        if (!conn) {
            continue;
        }
        conn->stop();
    }
}

RPCServer::~RPCServer() {
    fmt::print(stderr, "~RPCServer(\"{}\")\n", _s.path());
    stop();
    _accept_thread.request_stop();
}

}; // namespace unformat
