#include <clang-unformat-ng/rpc.hpp>

#include "boost/leaf/handle_errors.hpp"
#include "clang-unformat-ng/common.hpp"
#include "common-internal.hpp"

#include <clang-unformat-ng/fmt.hpp>
#include <clang-unformat-ng/utils.hpp>

#include <chrono>
#include <functional>
#include <memory>
#include <sys/socket.h>
#include <sys/un.h>

#include <enchantum/enchantum.hpp>
#include <fmt/format.h>

using namespace std::literals;

namespace unformat {

/// RPCServerConnection
RPCServerConnection::RPCServerConnection(int sock) : _s{sock} {
    fmt::print(stderr, "RPCServerConnection({})\n", "fixme");
}

// [&]() -> result<void> { return {}; }, []() -> void {}

void RPCServerConnection::rpc_thread_func(std::stop_token stok) {
    std::stop_callback callback(stok, [this] {
        fmt::print(stderr, "RPCServerConnection::rpc_thread_func stop callback\n");
        leaf::try_handle_all(
            [&]() -> result<void> {
                BOOST_LEAF_CHECK(_s.shutdown());
                // (void)this;
                return {};
            },
            []() -> void {
                fmt::print(stderr, "RPCServerConnection::rpc_thread_func stop CB error\n");
            });
    });
    leaf::try_handle_all(
        [&]() -> result<void> {
            fmt::print(stderr, "RPCServerConnection::rpc_thread_func entry\n");
            while (!stok.stop_requested()) {
                fmt::print(stderr, "RPCServerConnection::rpc_thread_func loop\n");
                const auto resp = "{\"resp\": 200}"s;
                BOOST_LEAF_AUTO(in_msg, LengthPrefixProtocol<>::read_str(_s));
                fmt::print(stderr, "in_msg sz: {} buf: \"{:s}\"\n", in_msg.size(), in_msg);
                BOOST_LEAF_CHECK(LengthPrefixProtocol<>::write_str(_s, resp));
            }
            fmt::print(stderr, "RPCServerConnection::rpc_thread_func exit\n");
            return {};
        },
        [&](leaf::match<sock_et, sock_et::recv_dead, sock_et::send_dead>) -> void {
            fmt::print(stderr, "RPCServerConnection::rpc_thread_func sock recv_dead\n");
            const auto sdr = _s.shutdown();
            if (!sdr) {
                fmt::print(stderr, "RPCServerConnection::rpc_thread_func sock recv_dead shutdown fail\n");
            }
        },
        [&](leaf::match<sock_et, sock_et::send_dead>) -> void {
            fmt::print(stderr, "RPCServerConnection::rpc_thread_func sock send_dead\n");
            const auto sdr = _s.shutdown();
            if (!sdr) {
                fmt::print(stderr, "RPCServerConnection::rpc_thread_func sock send_dead shutdown fail\n");
            }
        },
        [](const sock_et &se, leaf::e_errno const *errn) -> void {
            if (!errn) {
                fmt::print(stderr, "RPCServerConnection::rpc_thread_func sock error: {} errno: nil\n",
                           enchantum::to_string(se));
            } else {
                fmt::print(stderr, "RPCServerConnection::rpc_thread_func sock error: {} errno: {}\n",
                           enchantum::to_string(se), *errn);
            }
        },
        []() -> void {
            fmt::print(stderr, "RPCServerConnection::rpc_thread_func other error\n");
        });
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
    fmt::print(stderr, "~RPCServerConnection({})\n", "fixme");
    stop();
}

size_t RPCServerConnection::hash() const noexcept {
    return _s.hash();
}

/// RPCServer
RPCServer::RPCServer(const std::string &socket_path) : _s{socket_path} {
    fmt::print(stderr, "RPCServer({})\n", "fixme");
}

void RPCServer::accept_thread_func(std::stop_token stok) {
    leaf::try_handle_all(
        [&]() -> result<void> {
            fmt::print(stderr, "RPCServer::accept_thread_func entry\n");

            std::stop_callback callback(stok, [this] {
                fmt::print(stderr, "RPCServer::accept_thread_func stop callback\n");
                // _s.shutdown();
                (void)this;
            });

            BOOST_LEAF_CHECK(_s.listen());
            while (!stok.stop_requested()) {
                fmt::print(stderr, "RPCServer::accept_thread_func loop\n");
                BOOST_LEAF_AUTO(accept_res, _s.accept());
                auto [new_sock, remote_addr, remote_addr_len] = accept_res;
                fmt::print(stderr, "accept: new_sock: {} raddr: {} raddr_sz: {}\n", new_sock, remote_addr,
                           remote_addr_len);
                auto conn = std::make_unique<RPCServerConnection>(new_sock);
                fmt::print(stderr, "RPCServer::accept_thread_func loop RPCServerConnection created\n");
                auto [it, added] = _connections.emplace(std::move(conn));
                assert(added);
                if (*it) {
                    (*it)->run();
                    auto conn_stok = (*it)->run();
                    std::stop_callback conn_cb(conn_stok.get_token(), [this] {
                        fmt::print(stderr, "RPCServer::accept_thread_func conn_cb callback\n");
                        // _connections.erase(conn);
                        (void)this;
                    });
                }
            }
            fmt::print(stderr, "RPCServer::accept_thread_func exit\n");
            return {};
        },
        []() -> void {
            fmt::print(stderr, "RPCServer::accept_thread_func other error\n");
        });
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
}

} // namespace unformat
