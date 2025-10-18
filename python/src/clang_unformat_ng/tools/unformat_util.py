#!/usr/bin/env python3

import argparse

from rich.pretty import pprint

import clang_unformat_ng.styleopts as sopts


def dump_opts():
    pprint(sopts.opts)


def get_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(prog="clang-unformat-ng-py-util")
    parser.add_argument("--dump-opts", action="store_true", help="Dump style opts")
    return parser


def real_main(args: argparse.Namespace):
    print(f"args: {args}")
    if args.dump_opts:
        dump_opts()


def main():
    parser = get_arg_parser()
    args = parser.parse_args()
    real_main(args)


if __name__ == "__main__":
    main()
