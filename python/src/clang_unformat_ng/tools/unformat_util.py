#!/usr/bin/env python3

import argparse
import time

from rich import print
from rich.pretty import pprint

import clang_unformat_ng.rpc as rpc
import clang_unformat_ng.styleopts.data as sopts_data
import clang_unformat_ng.styleopts.template as sopts_tmpl


def do_dump_opts() -> None:
    pprint(sopts_data.opts)
    # builtins.print(sopts_data.opts.values())


def do_template(out_path: str) -> None:
    print("doing template")
    # sia_opt = sopts_data.opts["SpacesInAngles"]
    # sip_opt = sopts_data.opts["SpacesInParens"]
    # # if not isinstance(sia_opt, )
    # print("sia_opt:")
    # pprint(sia_opt)
    # print("sip_opt:")
    # pprint(sip_opt)
    opts_list = list(sopts_data.opts.values())
    r = sopts_tmpl.render_rfl(opts_list)
    with open(out_path, "w") as outf:
        outf.write(r)


def do_etc() -> None:
    print("doing etc")
    # opt_vals = opts.values()

    # collim_opt = opts["ColumnLimit"]
    # print(f"collim_opt: {collim_opt}")

    # v = unstructure(collim_opt, tuple(opts.values()))
    # pprint(v)


def do_rpc(sock_path: str) -> None:
    client = rpc.RPCClient(sock_path)
    while True:
        time.sleep(1)
        client.write(b"helo\0")
        recv = client.read()
        print(f"rpc recv: {recv}")
        # time.sleep(1)


def get_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(prog="clang-unformat-ng-py-util")
    parser.add_argument("--dump-opts", action="store_true", help="Dump style opts")
    parser.add_argument("--template", action="store_true", help="Do template stuff")
    parser.add_argument("--rpc", metavar="SOCKPATH", help="Connect to RPC server")
    parser.add_argument("--etc", action="store_true", help="Do other scratch work stuff")
    # parser.add_argument("-i", "--input", help="input path")
    parser.add_argument("-o", "--out", help="output path")
    return parser


def real_main(args: argparse.Namespace):
    print(f"args: {args}")
    if args.dump_opts:
        do_dump_opts()
    elif args.etc:
        do_etc()
    elif args.template:
        if not args.out:
            raise ValueError("need input and output")
        do_template(args.out)
    elif args.rpc:
        do_rpc(args.rpc)


def main():
    parser = get_arg_parser()
    args = parser.parse_args()
    real_main(args)


if __name__ == "__main__":
    main()
