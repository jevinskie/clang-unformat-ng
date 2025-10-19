from jinja2 import Environment, PackageLoader, select_autoescape

env = Environment(
    loader=PackageLoader("styleopts"),
    autoescape=select_autoescape(
        enabled_extensions=("cpp"),
        default_for_string=True,
    ),
)
