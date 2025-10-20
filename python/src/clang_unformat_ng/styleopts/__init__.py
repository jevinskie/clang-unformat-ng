from clang_unformat_ng.styleopts.types import (
    Type,
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


def is_bool(ty: Type) -> bool:
    return ty == BOOL_TYPE


def is_number(ty: Type) -> bool:
    return ty == UINT_TYPE or ty == SINT_TYPE


def is_uint(ty: Type) -> bool:
    return ty == UINT_TYPE


def is_sint(ty: Type) -> bool:
    return ty == SINT_TYPE


def is_str(ty: Type) -> bool:
    return ty == STR_TYPE


def is_str_list(ty: Type) -> bool:
    return ty == STR_LIST_TYPE
