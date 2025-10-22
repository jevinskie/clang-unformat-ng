from attrs import evolve
from jinja2 import Environment, PackageLoader, select_autoescape
from rich import print as rprint

# from rich import print as rprint
from clang_unformat_ng.styleopts.types import BOOL_TYPE, SINT_TYPE, UINT_TYPE, Option

env = Environment(
    loader=PackageLoader("clang_unformat_ng.styleopts"),
    autoescape=select_autoescape(
        enabled_extensions=("tcpp"),
        default_for_string=True,
    ),
)


def render_enum(opt: Option) -> str:
    eb = "SIAS_Never,\nSIAS_Always,\nSIAS_Leave"
    return eb


def render_rfl(opts: list[Option], **kwargs) -> str:
    template = env.get_template("rfl.tcpp")
    std_numeric = list(filter(lambda x: x.type in (BOOL_TYPE, UINT_TYPE, SINT_TYPE), opts))
    enums = list(filter(lambda x: x.enum is not None, opts))

    enums_none = list(filter(lambda x: x.type.cxx_qual is None, enums))
    enums_new = list(
        map(lambda x: evolve(x, **{"type": evolve(x.type, **{"cxx_qual": "clang::format::FormatStyle"})}), enums_none)
    )
    rprint(enums_new)

    # other = filter(lambda x: x.enum is None and x.nested_struct is None, opts)
    # rprint(list(other))
    # lopts = list((*std, *enums))
    lopts = list((
        *std_numeric,
        *enums_new,
    ))
    # rprint(lopts)
    return template.render(opts=lopts)
