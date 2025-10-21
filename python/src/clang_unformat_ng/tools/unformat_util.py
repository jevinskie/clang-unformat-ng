#!/usr/bin/env python3

import argparse

from rich import print
from rich.pretty import pprint

import clang_unformat_ng.styleopts.data as sopts_data
import clang_unformat_ng.styleopts.template as sopts_tmpl


def do_dump_opts():
    pprint(sopts_data.opts)
    # builtins.print(sopts_data.opts.values())


def do_template():
    print("doing template")
    sia_opt = sopts_data.opts["SpacesInAngles"]
    sip_opt = sopts_data.opts["SpacesInParens"]
    # if not isinstance(sia_opt, )
    print("sia_opt:")
    pprint(sia_opt)
    print("sip_opt:")
    pprint(sip_opt)
    r = sopts_tmpl.render_rfl([sia_opt, sip_opt])
    print(r)


def do_etc():
    print("doing etc")
    # opt_vals = opts.values()

    # collim_opt = opts["ColumnLimit"]
    # print(f"collim_opt: {collim_opt}")

    # v = unstructure(collim_opt, tuple(opts.values()))
    # pprint(v)


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
