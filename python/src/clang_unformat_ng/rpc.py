from __future__ import annotations

import socket
from collections.abc import Callable
from typing import ClassVar, Final, TypeVar

from attrs import define, field

T = TypeVar("T")

ReadFunc = Callable[[int], bytes]
WriteFunc = Callable[[bytes], None]


@define(auto_attribs=True, frozen=True)
class LengthPrefixedProtocol:
    read_func: ReadFunc
    write_func: WriteFunc
    LENGTH_BYTES: ClassVar[Final[int]] = 4

    def read(self) -> bytes:
        sz_bytes = self.read_func(self.LENGTH_BYTES)
        sz_val = int.from_bytes(sz_bytes, "little")
        return self.read_func(sz_val)

    def write(self, msg: bytes) -> None:
        sz_val = len(msg)
        sz_bytes = sz_val.to_bytes(self.LENGTH_BYTES, "little")
        self.write_func(sz_bytes + msg)


@define(auto_attribs=True)
class UnixSocket:
    sock_path: Final[str]
    sock: socket.socket = field(init=False)

    def __attrs_post_init__(self) -> None:
        self.sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        print(f"sock1: {self.sock}")
        self.sock.connect(self.sock_path)
        print(f"sock2: {self.sock}")

    def read(self, sz: int) -> bytes:
        print(f"read sz: {sz}")
        buf = self.sock.recv(sz)
        print(f"read buf len: {len(buf)} buf: {buf} sock: {self.sock}")
        return buf

    def write(self, buf: bytes) -> None:
        print(f"write sz: {len(buf)} buf: {buf}")
        res = self.sock.send(buf)
        print(f"write res: {res} sock: {self.sock}")


@define(auto_attribs=True, init=False)
class RPCClient:
    sock: UnixSocket
    lpp: LengthPrefixedProtocol

    def __init__(self, sock_path: str) -> None:
        self.sock = UnixSocket(sock_path)
        self.lpp = LengthPrefixedProtocol(self.sock.read, self.sock.write)

    def read(self) -> bytes:
        return self.lpp.read()

    def write(self, msg: bytes) -> None:
        self.lpp.write(msg)
