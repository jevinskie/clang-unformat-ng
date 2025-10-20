#!/usr/bin/env python3

import argparse

from attrs import define
from cattrs import structure
from rich.pretty import pprint

import clang_unformat_ng.styleopts as sopts
import clang_unformat_ng.styleopts_template as stmp
import clang_unformat_ng.styleopts_types as styp


def do_dump_opts():
    pprint(sopts.opts)


def do_template():
    print("doing template")
    stmp._do_template_test()


def do_etc():
    print("doing etc")
    opt_vals = sopts.opts.values()

    @define
    class Opts:
        opts: list[styp.Option]

    v = structure(opt_vals, list[styp.Option])
    pprint(v)


def get_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(prog="clang-unformat-ng-py-util")
    parser.add_argument("--dump-opts", action="store_true", help="Dump style opts")
    parser.add_argument("--template", action="store_true", help="Do template stuff")
    parser.add_argument("--etc", action="store_true", help="Do other scratch work stuff")
    return parser


def real_main(args: argparse.Namespace):
    print(f"args: {args}")
    if args.dump_opts:
        do_dump_opts()
    elif args.etc:
        do_etc()
    elif args.template:
        do_template()


def main():
    parser = get_arg_parser()
    args = parser.parse_args()
    real_main(args)


if __name__ == "__main__":
    main()
