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
    values: list[EnumValue] = Factory(list)


@define(auto_attribs=True, frozen=True)
class NestedEnum:
    name: str
    type: Type
    version: Version | None
    values: list[EnumValue] = Factory(list)


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


@define(auto_attribs=True)
class Option:
    name: str
    type: Type
    version: Version | None
    enum: Enum | None
    nested_struct: NestedStruct | None


def enum_cxx_type_name_is_deprecated(name: str) -> bool:
    return name in (
        "DefinitionReturnTypeBreakingStyle",
        "ReturnTypeBreakingStyle",
        "SpaceBeforeParensStyle",
    )
