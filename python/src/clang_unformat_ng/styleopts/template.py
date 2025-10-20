from jinja2 import Environment, PackageLoader, select_autoescape
from rich import print as rprint

env = Environment(
    loader=PackageLoader("clang_unformat_ng.styleopts"),
    autoescape=select_autoescape(
        enabled_extensions=("tcpp"),
        default_for_string=True,
    ),
)


def render_enum() -> str:
    eb = "SIAS_Never,\nSIAS_Always,\nSIAS_Leave"
    return eb


def render_rfl() -> str:
    r = ""
    template = env.get_template("rfl.cpp")
    rprint(template)
    rendered = template.render()
    rprint(rendered)
    r = rendered
    return r
