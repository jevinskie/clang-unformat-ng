from typing import Any, Literal

import cattrs
from attrs import Factory, define, evolve, field


@define(auto_attribs=True, frozen=True)
class Type:
    cxx_name: str
    yaml_name: str
    is_list: bool
    is_optional: bool
    is_deprecated: bool
    cxx_qual: str | None = field(default=None)


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

UNION_STD_TYPE_TUPLE = (BOOL_TYPE, UINT_TYPE, SINT_TYPE, STR_TYPE, STR_LIST_TYPE)


def is_std_ty(t: Type) -> bool:
    return t in UNION_STD_TYPE_TUPLE


@define(auto_attribs=True, frozen=True, order=True)
class Version:
    major: int
    minor: int | None


@define(auto_attribs=True, frozen=True, order=True)
class EnumValue:
    name: str
    config: str


@define(auto_attribs=True, frozen=True)
class Enum:
    name: str
    # type: Type = field(converter=lambda o: Type(**(asdict(inst=o) | {"cxx_qual": "clang::format::FormatStyle"})))
    type: Type
    values: list[EnumValue] = Factory(list)

    def __hash__(self) -> int:
        return hash((self.name, self.type, tuple(sorted(self.values))))


@define(auto_attribs=True, frozen=True)
class NestedEnum:
    name: str
    type: Type
    version: Version | None
    values: list[EnumValue] = Factory(list)

    def __eq__(self, other: Any) -> bool:
        if not isinstance(other, NestedEnum):
            raise TypeError(f"Expected NestedEnum, other is: {type(other)}")

        return (
            self.name == other.name
            and self.type == other.type
            and self.version == other.version
            and tuple(sorted(self.values)) == tuple(sorted(other.values))
        )

    def __lt__(self, other: Any) -> bool:
        if not isinstance(other, NestedEnum):
            raise TypeError(f"Expected NestedEnum, other is: {type(other)}")
        return (self.name, self.type, self.version, tuple(sorted(self.values))) < (
            other.name,
            other.type,
            other.version,
            tuple(sorted(other.values)),
        )

    def __hash__(self) -> int:
        return hash((self.name, self.type, self.version, tuple(sorted(self.values))))


@define(auto_attribs=True, frozen=True)
class NestedField:
    name: str
    type: Type
    version: Version | None

    def __lt__(self, other: Any) -> bool:
        if not isinstance(other, NestedField):
            raise TypeError(f"Expected NestedField, other is: {type(other)}")
        return (self.name, self.type, self.version) < (other.name, other.type, other.version)


@define(auto_attribs=True, frozen=True)
class NestedStruct:
    name: str
    type: Type
    values: list[NestedEnum | NestedField] = Factory(list)

    def __hash__(self) -> int:
        enum_vals = filter(lambda v: isinstance(v, NestedEnum), self.values)
        field_vals = filter(lambda v: isinstance(v, NestedField), self.values)
        return hash((self.name, self.type, tuple(sorted(enum_vals)), tuple(sorted(field_vals))))


@define(auto_attribs=True, frozen=True)
class Option:
    name: str
    type: Type
    version: Version | None
    enum: Enum | None
    nested_struct: NestedStruct | None

    @property
    def cxx_type(self) -> str:
        builtin_types = ("bool", "unsigned", "int", "std::string", "std::vector<std::string>")
        tyname = self.type.cxx_name
        if tyname in builtin_types:
            return tyname
        return f"{tyname}"

    @property
    def resolved_type(self) -> Type:
        return self.type
        if self.type.cxx_qual is not None:
            if self.enum or self.nested_struct:
                # return Type(**(asdict(self.type) | {"cxx_qual": "clang::Format::FormatStyle"}))
                return evolve(self.type, **{"cxx_qual": "clang::format::FormatStyle"})
        return self.type

    @property
    def plain(self) -> bool:
        return not ((self.enum is not None) or (self.nested_struct is not None))

    @property
    def is_str(self) -> bool:
        return self.type in (STR_TYPE, STR_LIST_TYPE)


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

UNION_STD_TYPE = (
    Literal[BOOL_TYPE] | Literal[UINT_TYPE] | Literal[SINT_TYPE] | Literal[STR_TYPE] | Literal[STR_LIST_TYPE]
)
UNION_STD_TYPE_TUPLE = (BOOL_TYPE, UINT_TYPE, SINT_TYPE, STR_TYPE, STR_LIST_TYPE)


def is_std(t: Type) -> bool:
    return t in UNION_STD_TYPE_TUPLE
