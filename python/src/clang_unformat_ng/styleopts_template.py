from jinja2 import Environment, PackageLoader, select_autoescape

env = Environment(
    loader=PackageLoader("clang_unformat_ng.styleopts"),
    autoescape=select_autoescape(
        enabled_extensions=("cpp"),
        default_for_string=True,
    ),
)

template = env.get_template("bool.cpp")

print(f"template: {template}")
