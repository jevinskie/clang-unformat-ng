import cattrs
from attrs import Factory, define


@define(auto_attribs=True, frozen=True)
class Type:
    cxx_name: str
    yaml_name: str
    is_list: bool
    is_optional: bool
    is_deprecated: bool


@define(auto_attribs=True, frozen=True)
class Version:
    major: int
    minor: int | None


@define(auto_attribs=True, frozen=True)
class EnumValue:
    name: str
    config: str


@define(auto_attribs=True, frozen=True)
class Enum:
    name: str
    type: Type
    values: list[EnumValue, ...] = Factory(list)


@define(auto_attribs=True, frozen=True)
class NestedEnum:
    name: str
    type: Type
    version: Version | None
    values: list[EnumValue, ...] = Factory(list)


@define(auto_attribs=True, frozen=True)
class NestedField:
    name: str
    type: Type
    version: Version | None


@define(auto_attribs=True, frozen=True)
class NestedStruct:
    name: str
    type: Type
    values: list[NestedEnum | NestedField] = Factory(list)


@define(auto_attribs=True, frozen=True)
class Option:
    name: str
    type: Type
    version: Version | None
    enum: Enum | None
    nested_struct: NestedStruct | None


# TODO: is needed? it calls attrs.resolve_types on all seralized classes
# _resolve_json_schema_obj_cls_types()

_converter = cattrs.Converter()


def _add_cattrs_hooks():
    pass


_add_cattrs_hooks()


def enum_cxx_type_name_is_deprecated(name: str) -> bool:
    return name in (
        "DefinitionReturnTypeBreakingStyle",
        "ReturnTypeBreakingStyle",
        "SpaceBeforeParensStyle",
    )


BOOL_TYPE = Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False)
UINT_TYPE = Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False)
SINT_TYPE = Type(cxx_name="int", yaml_name="Integer", is_list=False, is_optional=False, is_deprecated=False)
STR_TYPE = Type(cxx_name="std::string", yaml_name="String", is_list=False, is_optional=False, is_deprecated=False)
STR_LIST_TYPE = Type(
    cxx_name="std::vector<std::string>",
    yaml_name="List of Strings",
    is_list=True,
    is_optional=False,
    is_deprecated=False,
)
