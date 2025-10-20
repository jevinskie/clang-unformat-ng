from clang_unformat_ng.styleopts.types import BOOL_TYPE, SINT_TYPE, STR_LIST_TYPE, STR_TYPE, UINT_TYPE, Type


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
