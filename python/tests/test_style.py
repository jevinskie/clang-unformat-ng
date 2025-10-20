import clang_unformat_ng.styleopts as sopts
from clang_unformat_ng.styleopts.types import Enum, EnumValue, Option, Type, Version
from clang_unformat_ng.utils import shrink_spaces as sp


def test_styp():
    opt = Option(
        name="SpacesInAngles",
        type=Type(
            cxx_name="SpacesInAnglesStyle",
            yaml_name="SpacesInAnglesStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        version=Version(major=3, minor=4),
        enum=Enum(
            name="SpacesInAnglesStyle",
            type=Type(
                cxx_name="SpacesInAnglesStyle",
                yaml_name="SpacesInAnglesStyle",
                is_list=False,
                is_optional=False,
                is_deprecated=False,
            ),
            values=[
                EnumValue(name="SIAS_Never", config="SIAS_Never"),
                EnumValue(name="SIAS_Always", config="SIAS_Always"),
                EnumValue(name="SIAS_Leave", config="SIAS_Leave"),
            ],
        ),
        nested_struct=None,
    )
    golden = """
enum SpacesInAnglesStyle {
  SIAS_Never,
  SIAS_Always,
  SIAS_Leave
};
SpacesInAnglesStyle SpacesInAngles;
"""
    rendered = sopts.render_option(opt)
    print("golden:")
    print(golden)
    print("rendered:")
    print(rendered)
    assert sp(golden) == sp(rendered)
