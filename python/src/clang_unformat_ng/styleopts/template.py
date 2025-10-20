from jinja2 import Environment, PackageLoader, select_autoescape
from rich import print as rprint

env = Environment(
    loader=PackageLoader("clang_unformat_ng.styleopts"),
    autoescape=select_autoescape(
        enabled_extensions=("tcpp"),
        default_for_string=True,
    ),
)


def _do_template_test():
    template = env.get_template("bool.tcpp")
    rprint(f"template: {template}")
    rnd = template.render()
    rprint("rnd:")
    rprint(rnd)
