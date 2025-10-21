from jinja2 import Environment, PackageLoader, select_autoescape

from clang_unformat_ng.styleopts.types import Option

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
    enums = filter(lambda x: x.enum is not None, opts)
    return template.render(enums=enums)
