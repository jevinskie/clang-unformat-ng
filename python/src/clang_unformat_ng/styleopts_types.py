from attrs import Factory, define, field


@define(auto_attribs=True, frozen=True)
class Type:
    cxx_name: str = field(kw_only=True)
    yaml_name: str = field(kw_only=True)
    is_list: bool = field(kw_only=True)
    is_optional: bool = field(kw_only=True)
    is_deprecated: bool = field(kw_only=True)


@define(auto_attribs=True, frozen=True)
class Version:
    major: int = field(kw_only=True)
    minor: int | None = field(default=None)


@define(auto_attribs=True, frozen=True)
class NestedField:
    name: str = field(kw_only=True)
    type: Type = field(kw_only=True)
    version: Version | None = field(default=None)


@define(auto_attribs=True, frozen=True)
class EnumValue:
    name: str = field(kw_only=True)
    config: str = field(kw_only=True)


@define(auto_attribs=True, frozen=True)
class Enum:
    name: str
    type: Type
    values: list[EnumValue] = Factory(list)


@define(auto_attribs=True, frozen=True)
class NestedEnum:
    name: str
    type: Type
    version: Version | None = field(kw_only=True)
    values: list = field(kw_only=True)


@define(auto_attribs=True, frozen=True)
class NestedStruct:
    name: str
    type: Type
    values: list[NestedEnum | NestedField] = Factory(list)


@define(auto_attribs=True)
class Option:
    name: str
    type: Type
    version: Version | None = field(default=None)
    enum: Enum | None = field(default=None)
    nested_struct: NestedStruct | None = field(default=None)


def enum_cxx_type_name_is_deprecated(name: str) -> bool:
    return name in (
        "DefinitionReturnTypeBreakingStyle",
        "ReturnTypeBreakingStyle",
        "SpaceBeforeParensStyle",
    )
