from attrs import Factory, define, field

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
class NestedField:
    name: str
    type: Type
    comment: str = field(converter=str.strip, repr=False)
    version: Version | None = field()


@define(auto_attribs=True, frozen=True)
class EnumValue:
    name: str
    comment: str = field(repr=False)
    config: str


@define(auto_attribs=True, frozen=True)
class Enum:
    name: str
    type: Type
    comment: str = field(converter=str.strip, repr=False)
    values: list[EnumValue] = Factory(list)

@define(auto_attribs=True, frozen=True)
class NestedEnum:
    name: str
    type: Type
    comment: str = field(repr=False)
    version: Version | None = field()
    values: list


@define(auto_attribs=True, frozen=True)
class NestedStruct:
    name: str
    type: Type
    comment: str = field(converter=str.strip, repr=False)
    values: list[NestedEnum | NestedField] = Factory(list)

    def __str__(self) -> str:
        return self.comment + "\n" + "\n".join(map(str, self.values))


@define(auto_attribs=True)
class Option:
    name: str
    type: Type
    comment: str = field(converter=str.strip, repr=False)
    version: Version | None = field()
    enum: Enum | None = field(init=False, default=None)
    nested_struct: NestedStruct | None = field(init=False, default=None)


def enum_cxx_type_name_is_deprecated(name: str) -> bool:
    return name in (
        "DefinitionReturnTypeBreakingStyle",
        "ReturnTypeBreakingStyle",
        "SpaceBeforeParensStyle",
    )
