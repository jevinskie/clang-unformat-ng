import re

_space_pat = re.compile(r"[:space:]+")


def shrink_spaces(s: str) -> str:
    return re.sub(_space_pat, " ", s, re.DOTALL)
