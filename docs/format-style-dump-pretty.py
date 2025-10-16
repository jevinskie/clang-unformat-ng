# type: ignore

# fmt: off
class Option: ...
class Type: ...
class Version: ...
class EnumValue: ...
class Enum: ...
class NestedEnum: ...
class NestedStruct: ...
class NestedField: ...
# fmt: on

Option(
    name="AccessModifierOffset",
    type=Type(cxx_name="int", yaml_name="Integer", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=3),
    enum=None,
    nested_struct=None,
)

Option(
    name="AlignAfterOpenBracket",
    type=Type(
        cxx_name="BracketAlignmentStyle",
        yaml_name="BracketAlignmentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=8),
    enum=Enum(
        name="BracketAlignmentStyle",
        type=Type(
            cxx_name="BracketAlignmentStyle",
            yaml_name="BracketAlignmentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BAS_Align", config="BAS_Align"),
            EnumValue(name="BAS_DontAlign", config="BAS_DontAlign"),
            EnumValue(name="BAS_AlwaysBreak", config="BAS_AlwaysBreak"),
            EnumValue(name="BAS_BlockIndent", config="BAS_BlockIndent"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AlignArrayOfStructures",
    type=Type(
        cxx_name="ArrayInitializerAlignmentStyle",
        yaml_name="ArrayInitializerAlignmentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=13, minor=None),
    enum=Enum(
        name="ArrayInitializerAlignmentStyle",
        type=Type(
            cxx_name="ArrayInitializerAlignmentStyle",
            yaml_name="ArrayInitializerAlignmentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="AIAS_Left", config="AIAS_Left"),
            EnumValue(name="AIAS_Right", config="AIAS_Right"),
            EnumValue(name="AIAS_None", config="AIAS_None"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AlignConsecutiveAssignments",
    type=Type(
        cxx_name="AlignConsecutiveStyle",
        yaml_name="AlignConsecutiveStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=8),
    enum=None,
    nested_struct=NestedStruct(
        name="AlignConsecutiveStyle",
        type=Type(
            cxx_name="AlignConsecutiveStyle",
            yaml_name="AlignConsecutiveStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Enabled",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossEmptyLines",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossComments",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignCompound",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionDeclarations",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionPointers",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="PadOperators",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="AlignConsecutiveBitFields",
    type=Type(
        cxx_name="AlignConsecutiveStyle",
        yaml_name="AlignConsecutiveStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=11, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="AlignConsecutiveStyle",
        type=Type(
            cxx_name="AlignConsecutiveStyle",
            yaml_name="AlignConsecutiveStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Enabled",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossEmptyLines",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossComments",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignCompound",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionDeclarations",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionPointers",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="PadOperators",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="AlignConsecutiveDeclarations",
    type=Type(
        cxx_name="AlignConsecutiveStyle",
        yaml_name="AlignConsecutiveStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=8),
    enum=None,
    nested_struct=NestedStruct(
        name="AlignConsecutiveStyle",
        type=Type(
            cxx_name="AlignConsecutiveStyle",
            yaml_name="AlignConsecutiveStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Enabled",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossEmptyLines",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossComments",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignCompound",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionDeclarations",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionPointers",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="PadOperators",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="AlignConsecutiveMacros",
    type=Type(
        cxx_name="AlignConsecutiveStyle",
        yaml_name="AlignConsecutiveStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=9, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="AlignConsecutiveStyle",
        type=Type(
            cxx_name="AlignConsecutiveStyle",
            yaml_name="AlignConsecutiveStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Enabled",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossEmptyLines",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossComments",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignCompound",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionDeclarations",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionPointers",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="PadOperators",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="AlignConsecutiveShortCaseStatements",
    type=Type(
        cxx_name="ShortCaseStatementsAlignmentStyle",
        yaml_name="ShortCaseStatementsAlignmentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=17, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="ShortCaseStatementsAlignmentStyle",
        type=Type(
            cxx_name="ShortCaseStatementsAlignmentStyle",
            yaml_name="ShortCaseStatementsAlignmentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Enabled",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossEmptyLines",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossComments",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignCaseArrows",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignCaseColons",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="AlignConsecutiveTableGenBreakingDAGArgColons",
    type=Type(
        cxx_name="AlignConsecutiveStyle",
        yaml_name="AlignConsecutiveStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=19, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="AlignConsecutiveStyle",
        type=Type(
            cxx_name="AlignConsecutiveStyle",
            yaml_name="AlignConsecutiveStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Enabled",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossEmptyLines",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossComments",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignCompound",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionDeclarations",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionPointers",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="PadOperators",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="AlignConsecutiveTableGenCondOperatorColons",
    type=Type(
        cxx_name="AlignConsecutiveStyle",
        yaml_name="AlignConsecutiveStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=19, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="AlignConsecutiveStyle",
        type=Type(
            cxx_name="AlignConsecutiveStyle",
            yaml_name="AlignConsecutiveStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Enabled",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossEmptyLines",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossComments",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignCompound",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionDeclarations",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionPointers",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="PadOperators",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="AlignConsecutiveTableGenDefinitionColons",
    type=Type(
        cxx_name="AlignConsecutiveStyle",
        yaml_name="AlignConsecutiveStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=19, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="AlignConsecutiveStyle",
        type=Type(
            cxx_name="AlignConsecutiveStyle",
            yaml_name="AlignConsecutiveStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Enabled",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossEmptyLines",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AcrossComments",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignCompound",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionDeclarations",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AlignFunctionPointers",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="PadOperators",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="AlignEscapedNewlines",
    type=Type(
        cxx_name="EscapedNewlineAlignmentStyle",
        yaml_name="EscapedNewlineAlignmentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=5, minor=None),
    enum=Enum(
        name="EscapedNewlineAlignmentStyle",
        type=Type(
            cxx_name="EscapedNewlineAlignmentStyle",
            yaml_name="EscapedNewlineAlignmentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="ENAS_DontAlign", config="ENAS_DontAlign"),
            EnumValue(name="ENAS_Left", config="ENAS_Left"),
            EnumValue(name="ENAS_LeftWithLastLine", config="ENAS_LeftWithLastLine"),
            EnumValue(name="ENAS_Right", config="ENAS_Right"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AlignOperands",
    type=Type(
        cxx_name="OperandAlignmentStyle",
        yaml_name="OperandAlignmentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=5),
    enum=Enum(
        name="OperandAlignmentStyle",
        type=Type(
            cxx_name="OperandAlignmentStyle",
            yaml_name="OperandAlignmentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="OAS_DontAlign", config="OAS_DontAlign"),
            EnumValue(name="OAS_Align", config="OAS_Align"),
            EnumValue(name="OAS_AlignAfterOperator", config="OAS_AlignAfterOperator"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AlignTrailingComments",
    type=Type(
        cxx_name="TrailingCommentsAlignmentStyle",
        yaml_name="TrailingCommentsAlignmentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=NestedStruct(
        name="TrailingCommentsAlignmentStyle",
        type=Type(
            cxx_name="TrailingCommentsAlignmentStyle",
            yaml_name="TrailingCommentsAlignmentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedEnum(
                name="Kind",
                type=Type(
                    cxx_name="TrailingCommentsAlignmentKinds",
                    yaml_name="TrailingCommentsAlignmentKinds",
                    is_list=False,
                    is_optional=False,
                    is_deprecated=False,
                ),
                version=None,
                values=[
                    EnumValue(name="TCAS_Leave", config="TCAS_Leave"),
                    EnumValue(name="TCAS_Always", config="TCAS_Always"),
                    EnumValue(name="TCAS_Never", config="TCAS_Never"),
                ],
            ),
            NestedField(
                name="OverEmptyLines",
                type=Type(
                    cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False
                ),
                version=None,
            ),
        ],
    ),
)

Option(
    name="AllowAllArgumentsOnNextLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=9, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="AllowAllConstructorInitializersOnNextLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=9, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="AllowAllParametersOfDeclarationOnNextLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=3),
    enum=None,
    nested_struct=None,
)

Option(
    name="AllowBreakBeforeNoexceptSpecifier",
    type=Type(
        cxx_name="BreakBeforeNoexceptSpecifierStyle",
        yaml_name="BreakBeforeNoexceptSpecifierStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=18, minor=None),
    enum=Enum(
        name="BreakBeforeNoexceptSpecifierStyle",
        type=Type(
            cxx_name="BreakBeforeNoexceptSpecifierStyle",
            yaml_name="BreakBeforeNoexceptSpecifierStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BBNSS_Never", config="BBNSS_Never"),
            EnumValue(name="BBNSS_OnlyWithParen", config="BBNSS_OnlyWithParen"),
            EnumValue(name="BBNSS_Always", config="BBNSS_Always"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AllowBreakBeforeQtProperty",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=22, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="AllowShortBlocksOnASingleLine",
    type=Type(
        cxx_name="ShortBlockStyle", yaml_name="ShortBlockStyle", is_list=False, is_optional=False, is_deprecated=False
    ),
    version=Version(major=3, minor=5),
    enum=Enum(
        name="ShortBlockStyle",
        type=Type(
            cxx_name="ShortBlockStyle",
            yaml_name="ShortBlockStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="SBS_Never", config="SBS_Never"),
            EnumValue(name="SBS_Empty", config="SBS_Empty"),
            EnumValue(name="SBS_Always", config="SBS_Always"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AllowShortCaseExpressionOnASingleLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=19, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="AllowShortCaseLabelsOnASingleLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=6),
    enum=None,
    nested_struct=None,
)

Option(
    name="AllowShortCompoundRequirementOnASingleLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=18, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="AllowShortEnumsOnASingleLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=11, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="AllowShortFunctionsOnASingleLine",
    type=Type(
        cxx_name="ShortFunctionStyle",
        yaml_name="ShortFunctionStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=5),
    enum=Enum(
        name="ShortFunctionStyle",
        type=Type(
            cxx_name="ShortFunctionStyle",
            yaml_name="ShortFunctionStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="SFS_None", config="SFS_None"),
            EnumValue(name="SFS_InlineOnly", config="SFS_InlineOnly"),
            EnumValue(name="SFS_Empty", config="SFS_Empty"),
            EnumValue(name="SFS_Inline", config="SFS_Inline"),
            EnumValue(name="SFS_All", config="SFS_All"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AllowShortIfStatementsOnASingleLine",
    type=Type(cxx_name="ShortIfStyle", yaml_name="ShortIfStyle", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=3),
    enum=Enum(
        name="ShortIfStyle",
        type=Type(
            cxx_name="ShortIfStyle", yaml_name="ShortIfStyle", is_list=False, is_optional=False, is_deprecated=False
        ),
        values=[
            EnumValue(name="SIS_Never", config="SIS_Never"),
            EnumValue(name="SIS_WithoutElse", config="SIS_WithoutElse"),
            EnumValue(name="SIS_OnlyFirstIf", config="SIS_OnlyFirstIf"),
            EnumValue(name="SIS_AllIfsAndElse", config="SIS_AllIfsAndElse"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AllowShortLambdasOnASingleLine",
    type=Type(
        cxx_name="ShortLambdaStyle", yaml_name="ShortLambdaStyle", is_list=False, is_optional=False, is_deprecated=False
    ),
    version=Version(major=9, minor=None),
    enum=Enum(
        name="ShortLambdaStyle",
        type=Type(
            cxx_name="ShortLambdaStyle",
            yaml_name="ShortLambdaStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="SLS_None", config="SLS_None"),
            EnumValue(name="SLS_Empty", config="SLS_Empty"),
            EnumValue(name="SLS_Inline", config="SLS_Inline"),
            EnumValue(name="SLS_All", config="SLS_All"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AllowShortLoopsOnASingleLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="AllowShortNamespacesOnASingleLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=20, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="AlwaysBreakAfterDefinitionReturnType",
    type=Type(
        cxx_name="DefinitionReturnTypeBreakingStyle",
        yaml_name="DefinitionReturnTypeBreakingStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=True,
    ),
    version=Version(major=3, minor=7),
    enum=Enum(
        name="DefinitionReturnTypeBreakingStyle",
        type=Type(
            cxx_name="DefinitionReturnTypeBreakingStyle",
            yaml_name="DefinitionReturnTypeBreakingStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=True,
        ),
        values=[
            EnumValue(name="DRTBS_None", config="DRTBS_None"),
            EnumValue(name="DRTBS_All", config="DRTBS_All"),
            EnumValue(name="DRTBS_TopLevel", config="DRTBS_TopLevel"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AlwaysBreakAfterReturnType",
    type=Type(
        cxx_name="ReturnTypeBreakingStyle",
        yaml_name="ReturnTypeBreakingStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=True,
    ),
    version=Version(major=3, minor=8),
    enum=Enum(
        name="ReturnTypeBreakingStyle",
        type=Type(
            cxx_name="ReturnTypeBreakingStyle",
            yaml_name="ReturnTypeBreakingStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=True,
        ),
        values=[
            EnumValue(name="RTBS_None", config="RTBS_None"),
            EnumValue(name="RTBS_Automatic", config="RTBS_Automatic"),
            EnumValue(name="RTBS_ExceptShortType", config="RTBS_ExceptShortType"),
            EnumValue(name="RTBS_All", config="RTBS_All"),
            EnumValue(name="RTBS_TopLevel", config="RTBS_TopLevel"),
            EnumValue(name="RTBS_AllDefinitions", config="RTBS_AllDefinitions"),
            EnumValue(name="RTBS_TopLevelDefinitions", config="RTBS_TopLevelDefinitions"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AlwaysBreakBeforeMultilineStrings",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=4),
    enum=None,
    nested_struct=None,
)

Option(
    name="AlwaysBreakTemplateDeclarations",
    type=Type(
        cxx_name="BreakTemplateDeclarationsStyle",
        yaml_name="BreakTemplateDeclarationsStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=4),
    enum=Enum(
        name="BreakTemplateDeclarationsStyle",
        type=Type(
            cxx_name="BreakTemplateDeclarationsStyle",
            yaml_name="BreakTemplateDeclarationsStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BTDS_Leave", config="BTDS_Leave"),
            EnumValue(name="BTDS_No", config="BTDS_No"),
            EnumValue(name="BTDS_MultiLine", config="BTDS_MultiLine"),
            EnumValue(name="BTDS_Yes", config="BTDS_Yes"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="AttributeMacros",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=12, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="BinPackArguments",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="BinPackLongBracedList",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=21, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="BinPackParameters",
    type=Type(
        cxx_name="BinPackParametersStyle",
        yaml_name="BinPackParametersStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=7),
    enum=Enum(
        name="BinPackParametersStyle",
        type=Type(
            cxx_name="BinPackParametersStyle",
            yaml_name="BinPackParametersStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BPPS_BinPack", config="BPPS_BinPack"),
            EnumValue(name="BPPS_OnePerLine", config="BPPS_OnePerLine"),
            EnumValue(name="BPPS_AlwaysOnePerLine", config="BPPS_AlwaysOnePerLine"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BitFieldColonSpacing",
    type=Type(
        cxx_name="BitFieldColonSpacingStyle",
        yaml_name="BitFieldColonSpacingStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=12, minor=None),
    enum=Enum(
        name="BitFieldColonSpacingStyle",
        type=Type(
            cxx_name="BitFieldColonSpacingStyle",
            yaml_name="BitFieldColonSpacingStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BFCS_Both", config="BFCS_Both"),
            EnumValue(name="BFCS_None", config="BFCS_None"),
            EnumValue(name="BFCS_Before", config="BFCS_Before"),
            EnumValue(name="BFCS_After", config="BFCS_After"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BraceWrapping",
    type=Type(
        cxx_name="BraceWrappingFlags",
        yaml_name="BraceWrappingFlags",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=8),
    enum=None,
    nested_struct=NestedStruct(
        name="BraceWrappingFlags",
        type=Type(
            cxx_name="BraceWrappingFlags",
            yaml_name="BraceWrappingFlags",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="AfterCaseLabel",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterClass",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedEnum(
                name="AfterControlStatement",
                type=Type(
                    cxx_name="BraceWrappingAfterControlStatementStyle",
                    yaml_name="BraceWrappingAfterControlStatementStyle",
                    is_list=False,
                    is_optional=False,
                    is_deprecated=False,
                ),
                version=None,
                values=[
                    EnumValue(name="BWACS_Never", config="BWACS_Never"),
                    EnumValue(name="BWACS_MultiLine", config="BWACS_MultiLine"),
                    EnumValue(name="BWACS_Always", config="BWACS_Always"),
                ],
            ),
            NestedField(
                name="AfterEnum",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterFunction",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterNamespace",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterObjCDeclaration",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterStruct",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterUnion",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterExternBlock",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="BeforeCatch",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="BeforeElse",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="BeforeLambdaBody",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="BeforeWhile",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="IndentBraces",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="SplitEmptyFunction",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="SplitEmptyRecord",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="SplitEmptyNamespace",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="BracedInitializerIndentWidth",
    type=Type(cxx_name="int", yaml_name="Integer", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=17, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="BreakAdjacentStringLiterals",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=18, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="BreakAfterAttributes",
    type=Type(
        cxx_name="AttributeBreakingStyle",
        yaml_name="AttributeBreakingStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=16, minor=None),
    enum=Enum(
        name="AttributeBreakingStyle",
        type=Type(
            cxx_name="AttributeBreakingStyle",
            yaml_name="AttributeBreakingStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="ABS_Always", config="ABS_Always"),
            EnumValue(name="ABS_Leave", config="ABS_Leave"),
            EnumValue(name="ABS_Never", config="ABS_Never"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BreakAfterJavaFieldAnnotations",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=8),
    enum=None,
    nested_struct=None,
)

Option(
    name="BreakAfterReturnType",
    type=Type(
        cxx_name="ReturnTypeBreakingStyle",
        yaml_name="ReturnTypeBreakingStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=True,
    ),
    version=Version(major=19, minor=None),
    enum=Enum(
        name="ReturnTypeBreakingStyle",
        type=Type(
            cxx_name="ReturnTypeBreakingStyle",
            yaml_name="ReturnTypeBreakingStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=True,
        ),
        values=[
            EnumValue(name="RTBS_None", config="RTBS_None"),
            EnumValue(name="RTBS_Automatic", config="RTBS_Automatic"),
            EnumValue(name="RTBS_ExceptShortType", config="RTBS_ExceptShortType"),
            EnumValue(name="RTBS_All", config="RTBS_All"),
            EnumValue(name="RTBS_TopLevel", config="RTBS_TopLevel"),
            EnumValue(name="RTBS_AllDefinitions", config="RTBS_AllDefinitions"),
            EnumValue(name="RTBS_TopLevelDefinitions", config="RTBS_TopLevelDefinitions"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BreakArrays",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=16, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="BreakBeforeBinaryOperators",
    type=Type(
        cxx_name="BinaryOperatorStyle",
        yaml_name="BinaryOperatorStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=6),
    enum=Enum(
        name="BinaryOperatorStyle",
        type=Type(
            cxx_name="BinaryOperatorStyle",
            yaml_name="BinaryOperatorStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BOS_None", config="BOS_None"),
            EnumValue(name="BOS_NonAssignment", config="BOS_NonAssignment"),
            EnumValue(name="BOS_All", config="BOS_All"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BreakBeforeBraces",
    type=Type(
        cxx_name="BraceBreakingStyle",
        yaml_name="BraceBreakingStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=7),
    enum=Enum(
        name="BraceBreakingStyle",
        type=Type(
            cxx_name="BraceBreakingStyle",
            yaml_name="BraceBreakingStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BS_Attach", config="BS_Attach"),
            EnumValue(name="BS_Linux", config="BS_Linux"),
            EnumValue(name="BS_Mozilla", config="BS_Mozilla"),
            EnumValue(name="BS_Stroustrup", config="BS_Stroustrup"),
            EnumValue(name="BS_Allman", config="BS_Allman"),
            EnumValue(name="BS_Whitesmiths", config="BS_Whitesmiths"),
            EnumValue(name="BS_GNU", config="BS_GNU"),
            EnumValue(name="BS_WebKit", config="BS_WebKit"),
            EnumValue(name="BS_Custom", config="BS_Custom"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BreakBeforeConceptDeclarations",
    type=Type(
        cxx_name="BreakBeforeConceptDeclarationsStyle",
        yaml_name="BreakBeforeConceptDeclarationsStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=12, minor=None),
    enum=Enum(
        name="BreakBeforeConceptDeclarationsStyle",
        type=Type(
            cxx_name="BreakBeforeConceptDeclarationsStyle",
            yaml_name="BreakBeforeConceptDeclarationsStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BBCDS_Never", config="BBCDS_Never"),
            EnumValue(name="BBCDS_Allowed", config="BBCDS_Allowed"),
            EnumValue(name="BBCDS_Always", config="BBCDS_Always"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BreakBeforeInlineASMColon",
    type=Type(
        cxx_name="BreakBeforeInlineASMColonStyle",
        yaml_name="BreakBeforeInlineASMColonStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=16, minor=None),
    enum=Enum(
        name="BreakBeforeInlineASMColonStyle",
        type=Type(
            cxx_name="BreakBeforeInlineASMColonStyle",
            yaml_name="BreakBeforeInlineASMColonStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BBIAS_Never", config="BBIAS_Never"),
            EnumValue(name="BBIAS_OnlyMultiline", config="BBIAS_OnlyMultiline"),
            EnumValue(name="BBIAS_Always", config="BBIAS_Always"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BreakBeforeTemplateCloser",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=21, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="BreakBeforeTernaryOperators",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="BreakBinaryOperations",
    type=Type(
        cxx_name="BreakBinaryOperationsStyle",
        yaml_name="BreakBinaryOperationsStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=20, minor=None),
    enum=Enum(
        name="BreakBinaryOperationsStyle",
        type=Type(
            cxx_name="BreakBinaryOperationsStyle",
            yaml_name="BreakBinaryOperationsStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BBO_Never", config="BBO_Never"),
            EnumValue(name="BBO_OnePerLine", config="BBO_OnePerLine"),
            EnumValue(name="BBO_RespectPrecedence", config="BBO_RespectPrecedence"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BreakConstructorInitializers",
    type=Type(
        cxx_name="BreakConstructorInitializersStyle",
        yaml_name="BreakConstructorInitializersStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=5, minor=None),
    enum=Enum(
        name="BreakConstructorInitializersStyle",
        type=Type(
            cxx_name="BreakConstructorInitializersStyle",
            yaml_name="BreakConstructorInitializersStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BCIS_BeforeColon", config="BCIS_BeforeColon"),
            EnumValue(name="BCIS_BeforeComma", config="BCIS_BeforeComma"),
            EnumValue(name="BCIS_AfterColon", config="BCIS_AfterColon"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BreakFunctionDefinitionParameters",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=19, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="BreakInheritanceList",
    type=Type(
        cxx_name="BreakInheritanceListStyle",
        yaml_name="BreakInheritanceListStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=7, minor=None),
    enum=Enum(
        name="BreakInheritanceListStyle",
        type=Type(
            cxx_name="BreakInheritanceListStyle",
            yaml_name="BreakInheritanceListStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BILS_BeforeColon", config="BILS_BeforeColon"),
            EnumValue(name="BILS_BeforeComma", config="BILS_BeforeComma"),
            EnumValue(name="BILS_AfterColon", config="BILS_AfterColon"),
            EnumValue(name="BILS_AfterComma", config="BILS_AfterComma"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="BreakStringLiterals",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=9),
    enum=None,
    nested_struct=None,
)

Option(
    name="BreakTemplateDeclarations",
    type=Type(
        cxx_name="BreakTemplateDeclarationsStyle",
        yaml_name="BreakTemplateDeclarationsStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=19, minor=None),
    enum=Enum(
        name="BreakTemplateDeclarationsStyle",
        type=Type(
            cxx_name="BreakTemplateDeclarationsStyle",
            yaml_name="BreakTemplateDeclarationsStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="BTDS_Leave", config="BTDS_Leave"),
            EnumValue(name="BTDS_No", config="BTDS_No"),
            EnumValue(name="BTDS_MultiLine", config="BTDS_MultiLine"),
            EnumValue(name="BTDS_Yes", config="BTDS_Yes"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="ColumnLimit",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="CommentPragmas",
    type=Type(cxx_name="std::string", yaml_name="String", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="CompactNamespaces",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=5, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="ConstructorInitializerAllOnOneLineOrOnePerLine",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="ConstructorInitializerIndentWidth",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="ContinuationIndentWidth",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="Cpp11BracedListStyle",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=4),
    enum=None,
    nested_struct=None,
)

Option(
    name="DeriveLineEnding",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=10, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="DerivePointerAlignment",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="DisableFormat",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="EmptyLineAfterAccessModifier",
    type=Type(
        cxx_name="EmptyLineAfterAccessModifierStyle",
        yaml_name="EmptyLineAfterAccessModifierStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=13, minor=None),
    enum=Enum(
        name="EmptyLineAfterAccessModifierStyle",
        type=Type(
            cxx_name="EmptyLineAfterAccessModifierStyle",
            yaml_name="EmptyLineAfterAccessModifierStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="ELAAMS_Never", config="ELAAMS_Never"),
            EnumValue(name="ELAAMS_Leave", config="ELAAMS_Leave"),
            EnumValue(name="ELAAMS_Always", config="ELAAMS_Always"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="EmptyLineBeforeAccessModifier",
    type=Type(
        cxx_name="EmptyLineBeforeAccessModifierStyle",
        yaml_name="EmptyLineBeforeAccessModifierStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=12, minor=None),
    enum=Enum(
        name="EmptyLineBeforeAccessModifierStyle",
        type=Type(
            cxx_name="EmptyLineBeforeAccessModifierStyle",
            yaml_name="EmptyLineBeforeAccessModifierStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="ELBAMS_Never", config="ELBAMS_Never"),
            EnumValue(name="ELBAMS_Leave", config="ELBAMS_Leave"),
            EnumValue(name="ELBAMS_LogicalBlock", config="ELBAMS_LogicalBlock"),
            EnumValue(name="ELBAMS_Always", config="ELBAMS_Always"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="EnumTrailingComma",
    type=Type(
        cxx_name="EnumTrailingCommaStyle",
        yaml_name="EnumTrailingCommaStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=21, minor=None),
    enum=Enum(
        name="EnumTrailingCommaStyle",
        type=Type(
            cxx_name="EnumTrailingCommaStyle",
            yaml_name="EnumTrailingCommaStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="ETC_Leave", config="ETC_Leave"),
            EnumValue(name="ETC_Insert", config="ETC_Insert"),
            EnumValue(name="ETC_Remove", config="ETC_Remove"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="ExperimentalAutoDetectBinPacking",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="FixNamespaceComments",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=5, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="ForEachMacros",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="IfMacros",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=13, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="IncludeBlocks",
    type=Type(
        cxx_name="IncludeBlocksStyle",
        yaml_name="IncludeBlocksStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=6, minor=None),
    enum=Enum(
        name="IncludeBlocksStyle",
        type=Type(
            cxx_name="IncludeBlocksStyle",
            yaml_name="IncludeBlocksStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="IBS_Preserve", config="IBS_Preserve"),
            EnumValue(name="IBS_Merge", config="IBS_Merge"),
            EnumValue(name="IBS_Regroup", config="IBS_Regroup"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="IncludeCategories",
    type=Type(
        cxx_name="std::vector<IncludeCategory>",
        yaml_name="List of IncludeCategories",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=8),
    enum=None,
    nested_struct=None,
)

Option(
    name="IncludeIsMainRegex",
    type=Type(cxx_name="std::string", yaml_name="String", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=9),
    enum=None,
    nested_struct=None,
)

Option(
    name="IncludeIsMainSourceRegex",
    type=Type(cxx_name="std::string", yaml_name="String", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=10, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="IndentAccessModifiers",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=13, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="IndentCaseBlocks",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=11, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="IndentCaseLabels",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=3),
    enum=None,
    nested_struct=None,
)

Option(
    name="IndentExportBlock",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=20, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="IndentExternBlock",
    type=Type(
        cxx_name="IndentExternBlockStyle",
        yaml_name="IndentExternBlockStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=11, minor=None),
    enum=Enum(
        name="IndentExternBlockStyle",
        type=Type(
            cxx_name="IndentExternBlockStyle",
            yaml_name="IndentExternBlockStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="IEBS_AfterExternBlock", config="IEBS_AfterExternBlock"),
            EnumValue(name="IEBS_NoIndent", config="IEBS_NoIndent"),
            EnumValue(name="IEBS_Indent", config="IEBS_Indent"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="IndentGotoLabels",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=10, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="IndentPPDirectives",
    type=Type(
        cxx_name="PPDirectiveIndentStyle",
        yaml_name="PPDirectiveIndentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=6, minor=None),
    enum=Enum(
        name="PPDirectiveIndentStyle",
        type=Type(
            cxx_name="PPDirectiveIndentStyle",
            yaml_name="PPDirectiveIndentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="PPDIS_None", config="PPDIS_None"),
            EnumValue(name="PPDIS_AfterHash", config="PPDIS_AfterHash"),
            EnumValue(name="PPDIS_BeforeHash", config="PPDIS_BeforeHash"),
            EnumValue(name="PPDIS_Leave", config="PPDIS_Leave"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="IndentRequiresClause",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=15, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="IndentWidth",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="IndentWrappedFunctionNames",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="InsertBraces",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=15, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="InsertNewlineAtEOF",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=16, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="InsertTrailingCommas",
    type=Type(
        cxx_name="TrailingCommaStyle",
        yaml_name="TrailingCommaStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=11, minor=None),
    enum=Enum(
        name="TrailingCommaStyle",
        type=Type(
            cxx_name="TrailingCommaStyle",
            yaml_name="TrailingCommaStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[EnumValue(name="TCS_None", config="TCS_None"), EnumValue(name="TCS_Wrapped", config="TCS_Wrapped")],
    ),
    nested_struct=None,
)

Option(
    name="IntegerLiteralSeparator",
    type=Type(
        cxx_name="IntegerLiteralSeparatorStyle",
        yaml_name="IntegerLiteralSeparatorStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=16, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="IntegerLiteralSeparatorStyle",
        type=Type(
            cxx_name="IntegerLiteralSeparatorStyle",
            yaml_name="IntegerLiteralSeparatorStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Binary",
                type=Type(cxx_name="int8_t", yaml_name="int8_t", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="BinaryMinDigits",
                type=Type(cxx_name="int8_t", yaml_name="int8_t", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="Decimal",
                type=Type(cxx_name="int8_t", yaml_name="int8_t", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="DecimalMinDigits",
                type=Type(cxx_name="int8_t", yaml_name="int8_t", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="Hex",
                type=Type(cxx_name="int8_t", yaml_name="int8_t", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="HexMinDigits",
                type=Type(cxx_name="int8_t", yaml_name="int8_t", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="JavaImportGroups",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=8, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="JavaScriptQuotes",
    type=Type(
        cxx_name="JavaScriptQuoteStyle",
        yaml_name="JavaScriptQuoteStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=9),
    enum=Enum(
        name="JavaScriptQuoteStyle",
        type=Type(
            cxx_name="JavaScriptQuoteStyle",
            yaml_name="JavaScriptQuoteStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="JSQS_Leave", config="JSQS_Leave"),
            EnumValue(name="JSQS_Single", config="JSQS_Single"),
            EnumValue(name="JSQS_Double", config="JSQS_Double"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="JavaScriptWrapImports",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=9),
    enum=None,
    nested_struct=None,
)

Option(
    name="KeepEmptyLines",
    type=Type(
        cxx_name="KeepEmptyLinesStyle",
        yaml_name="KeepEmptyLinesStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=19, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="KeepEmptyLinesStyle",
        type=Type(
            cxx_name="KeepEmptyLinesStyle",
            yaml_name="KeepEmptyLinesStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="AtEndOfFile",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AtStartOfBlock",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AtStartOfFile",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="KeepEmptyLinesAtEOF",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=17, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="KeepEmptyLinesAtTheStartOfBlocks",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="KeepFormFeed",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=20, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="LambdaBodyIndentation",
    type=Type(
        cxx_name="LambdaBodyIndentationKind",
        yaml_name="LambdaBodyIndentationKind",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=13, minor=None),
    enum=Enum(
        name="LambdaBodyIndentationKind",
        type=Type(
            cxx_name="LambdaBodyIndentationKind",
            yaml_name="LambdaBodyIndentationKind",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="LBI_Signature", config="LBI_Signature"),
            EnumValue(name="LBI_OuterScope", config="LBI_OuterScope"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="Language",
    type=Type(cxx_name="LanguageKind", yaml_name="LanguageKind", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=5),
    enum=Enum(
        name="LanguageKind",
        type=Type(
            cxx_name="LanguageKind", yaml_name="LanguageKind", is_list=False, is_optional=False, is_deprecated=False
        ),
        values=[
            EnumValue(name="LK_None", config="LK_None"),
            EnumValue(name="LK_C", config="LK_C"),
            EnumValue(name="LK_Cpp", config="LK_Cpp"),
            EnumValue(name="LK_CSharp", config="LK_CSharp"),
            EnumValue(name="LK_Java", config="LK_Java"),
            EnumValue(name="LK_JavaScript", config="LK_JavaScript"),
            EnumValue(name="LK_Json", config="LK_Json"),
            EnumValue(name="LK_ObjC", config="LK_ObjC"),
            EnumValue(name="LK_Proto", config="LK_Proto"),
            EnumValue(name="LK_TableGen", config="LK_TableGen"),
            EnumValue(name="LK_TextProto", config="LK_TextProto"),
            EnumValue(name="LK_Verilog", config="LK_Verilog"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="LineEnding",
    type=Type(
        cxx_name="LineEndingStyle", yaml_name="LineEndingStyle", is_list=False, is_optional=False, is_deprecated=False
    ),
    version=Version(major=16, minor=None),
    enum=Enum(
        name="LineEndingStyle",
        type=Type(
            cxx_name="LineEndingStyle",
            yaml_name="LineEndingStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="LE_LF", config="LE_LF"),
            EnumValue(name="LE_CRLF", config="LE_CRLF"),
            EnumValue(name="LE_DeriveLF", config="LE_DeriveLF"),
            EnumValue(name="LE_DeriveCRLF", config="LE_DeriveCRLF"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="MacroBlockBegin",
    type=Type(cxx_name="std::string", yaml_name="String", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="MacroBlockEnd",
    type=Type(cxx_name="std::string", yaml_name="String", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="Macros",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=17, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="MacrosSkippedByRemoveParentheses",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=21, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="MainIncludeChar",
    type=Type(
        cxx_name="MainIncludeCharDiscriminator",
        yaml_name="MainIncludeCharDiscriminator",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=19, minor=None),
    enum=Enum(
        name="MainIncludeCharDiscriminator",
        type=Type(
            cxx_name="MainIncludeCharDiscriminator",
            yaml_name="MainIncludeCharDiscriminator",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="MICD_Quote", config="MICD_Quote"),
            EnumValue(name="MICD_AngleBracket", config="MICD_AngleBracket"),
            EnumValue(name="MICD_Any", config="MICD_Any"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="MaxEmptyLinesToKeep",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="NamespaceIndentation",
    type=Type(
        cxx_name="NamespaceIndentationKind",
        yaml_name="NamespaceIndentationKind",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=7),
    enum=Enum(
        name="NamespaceIndentationKind",
        type=Type(
            cxx_name="NamespaceIndentationKind",
            yaml_name="NamespaceIndentationKind",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="NI_None", config="NI_None"),
            EnumValue(name="NI_Inner", config="NI_Inner"),
            EnumValue(name="NI_All", config="NI_All"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="NamespaceMacros",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=9, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="NumericLiteralCase",
    type=Type(
        cxx_name="NumericLiteralCaseStyle",
        yaml_name="NumericLiteralCaseStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=22, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="NumericLiteralCaseStyle",
        type=Type(
            cxx_name="NumericLiteralCaseStyle",
            yaml_name="NumericLiteralCaseStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedEnum(
                name="ExponentLetter",
                type=Type(
                    cxx_name="NumericLiteralComponentStyle",
                    yaml_name="NumericLiteralComponentStyle",
                    is_list=False,
                    is_optional=False,
                    is_deprecated=False,
                ),
                version=None,
                values=[
                    EnumValue(name="NLCS_Leave", config="NLCS_Leave"),
                    EnumValue(name="NLCS_Upper", config="NLCS_Upper"),
                    EnumValue(name="NLCS_Lower", config="NLCS_Lower"),
                ],
            ),
            NestedEnum(
                name="HexDigit",
                type=Type(
                    cxx_name="NumericLiteralComponentStyle",
                    yaml_name="NumericLiteralComponentStyle",
                    is_list=False,
                    is_optional=False,
                    is_deprecated=False,
                ),
                version=None,
                values=[
                    EnumValue(name="NLCS_Leave", config="NLCS_Leave"),
                    EnumValue(name="NLCS_Upper", config="NLCS_Upper"),
                    EnumValue(name="NLCS_Lower", config="NLCS_Lower"),
                ],
            ),
            NestedEnum(
                name="Prefix",
                type=Type(
                    cxx_name="NumericLiteralComponentStyle",
                    yaml_name="NumericLiteralComponentStyle",
                    is_list=False,
                    is_optional=False,
                    is_deprecated=False,
                ),
                version=None,
                values=[
                    EnumValue(name="NLCS_Leave", config="NLCS_Leave"),
                    EnumValue(name="NLCS_Upper", config="NLCS_Upper"),
                    EnumValue(name="NLCS_Lower", config="NLCS_Lower"),
                ],
            ),
            NestedEnum(
                name="Suffix",
                type=Type(
                    cxx_name="NumericLiteralComponentStyle",
                    yaml_name="NumericLiteralComponentStyle",
                    is_list=False,
                    is_optional=False,
                    is_deprecated=False,
                ),
                version=None,
                values=[
                    EnumValue(name="NLCS_Leave", config="NLCS_Leave"),
                    EnumValue(name="NLCS_Upper", config="NLCS_Upper"),
                    EnumValue(name="NLCS_Lower", config="NLCS_Lower"),
                ],
            ),
        ],
    ),
)

Option(
    name="ObjCBinPackProtocolList",
    type=Type(cxx_name="BinPackStyle", yaml_name="BinPackStyle", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=7, minor=None),
    enum=Enum(
        name="BinPackStyle",
        type=Type(
            cxx_name="BinPackStyle", yaml_name="BinPackStyle", is_list=False, is_optional=False, is_deprecated=False
        ),
        values=[
            EnumValue(name="BPS_Auto", config="BPS_Auto"),
            EnumValue(name="BPS_Always", config="BPS_Always"),
            EnumValue(name="BPS_Never", config="BPS_Never"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="ObjCBlockIndentWidth",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="ObjCBreakBeforeNestedBlockParam",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=11, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="ObjCPropertyAttributeOrder",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=18, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="ObjCSpaceAfterProperty",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="ObjCSpaceBeforeProtocolList",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="OneLineFormatOffRegex",
    type=Type(cxx_name="std::string", yaml_name="String", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=21, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="PPIndentWidth",
    type=Type(cxx_name="int", yaml_name="Integer", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=13, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="PackConstructorInitializers",
    type=Type(
        cxx_name="PackConstructorInitializersStyle",
        yaml_name="PackConstructorInitializersStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=14, minor=None),
    enum=Enum(
        name="PackConstructorInitializersStyle",
        type=Type(
            cxx_name="PackConstructorInitializersStyle",
            yaml_name="PackConstructorInitializersStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="PCIS_Never", config="PCIS_Never"),
            EnumValue(name="PCIS_BinPack", config="PCIS_BinPack"),
            EnumValue(name="PCIS_CurrentLine", config="PCIS_CurrentLine"),
            EnumValue(name="PCIS_NextLine", config="PCIS_NextLine"),
            EnumValue(name="PCIS_NextLineOnly", config="PCIS_NextLineOnly"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="PenaltyBreakAssignment",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=5, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyBreakBeforeFirstCallParameter",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyBreakBeforeMemberAccess",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=20, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyBreakComment",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyBreakFirstLessLess",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyBreakOpenParenthesis",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=14, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyBreakScopeResolution",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=18, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyBreakString",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyBreakTemplateDeclaration",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=7, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyExcessCharacter",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyIndentedWhitespace",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=12, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="PenaltyReturnTypeOnItsOwnLine",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="PointerAlignment",
    type=Type(
        cxx_name="PointerAlignmentStyle",
        yaml_name="PointerAlignmentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=7),
    enum=Enum(
        name="PointerAlignmentStyle",
        type=Type(
            cxx_name="PointerAlignmentStyle",
            yaml_name="PointerAlignmentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="PAS_Left", config="PAS_Left"),
            EnumValue(name="PAS_Right", config="PAS_Right"),
            EnumValue(name="PAS_Middle", config="PAS_Middle"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="QualifierAlignment",
    type=Type(
        cxx_name="QualifierAlignmentStyle",
        yaml_name="QualifierAlignmentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=14, minor=None),
    enum=Enum(
        name="QualifierAlignmentStyle",
        type=Type(
            cxx_name="QualifierAlignmentStyle",
            yaml_name="QualifierAlignmentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="QAS_Leave", config="QAS_Leave"),
            EnumValue(name="QAS_Left", config="QAS_Left"),
            EnumValue(name="QAS_Right", config="QAS_Right"),
            EnumValue(name="QAS_Custom", config="QAS_Custom"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="QualifierOrder",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=14, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="RawStringFormats",
    type=Type(
        cxx_name="std::vector<RawStringFormat>",
        yaml_name="List of RawStringFormats",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=6, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="ReferenceAlignment",
    type=Type(
        cxx_name="ReferenceAlignmentStyle",
        yaml_name="ReferenceAlignmentStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=13, minor=None),
    enum=Enum(
        name="ReferenceAlignmentStyle",
        type=Type(
            cxx_name="ReferenceAlignmentStyle",
            yaml_name="ReferenceAlignmentStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="RAS_Pointer", config="RAS_Pointer"),
            EnumValue(name="RAS_Left", config="RAS_Left"),
            EnumValue(name="RAS_Right", config="RAS_Right"),
            EnumValue(name="RAS_Middle", config="RAS_Middle"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="ReflowComments",
    type=Type(
        cxx_name="ReflowCommentsStyle",
        yaml_name="ReflowCommentsStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=8),
    enum=Enum(
        name="ReflowCommentsStyle",
        type=Type(
            cxx_name="ReflowCommentsStyle",
            yaml_name="ReflowCommentsStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="RCS_Never", config="RCS_Never"),
            EnumValue(name="RCS_IndentOnly", config="RCS_IndentOnly"),
            EnumValue(name="RCS_Always", config="RCS_Always"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="RemoveBracesLLVM",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=14, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="RemoveEmptyLinesInUnwrappedLines",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=20, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="RemoveParentheses",
    type=Type(
        cxx_name="RemoveParenthesesStyle",
        yaml_name="RemoveParenthesesStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=17, minor=None),
    enum=Enum(
        name="RemoveParenthesesStyle",
        type=Type(
            cxx_name="RemoveParenthesesStyle",
            yaml_name="RemoveParenthesesStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="RPS_Leave", config="RPS_Leave"),
            EnumValue(name="RPS_MultipleParentheses", config="RPS_MultipleParentheses"),
            EnumValue(name="RPS_ReturnStatement", config="RPS_ReturnStatement"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="RemoveSemicolon",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=16, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="RequiresClausePosition",
    type=Type(
        cxx_name="RequiresClausePositionStyle",
        yaml_name="RequiresClausePositionStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=15, minor=None),
    enum=Enum(
        name="RequiresClausePositionStyle",
        type=Type(
            cxx_name="RequiresClausePositionStyle",
            yaml_name="RequiresClausePositionStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="RCPS_OwnLine", config="RCPS_OwnLine"),
            EnumValue(name="RCPS_OwnLineWithBrace", config="RCPS_OwnLineWithBrace"),
            EnumValue(name="RCPS_WithPreceding", config="RCPS_WithPreceding"),
            EnumValue(name="RCPS_WithFollowing", config="RCPS_WithFollowing"),
            EnumValue(name="RCPS_SingleLine", config="RCPS_SingleLine"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="RequiresExpressionIndentation",
    type=Type(
        cxx_name="RequiresExpressionIndentationKind",
        yaml_name="RequiresExpressionIndentationKind",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=16, minor=None),
    enum=Enum(
        name="RequiresExpressionIndentationKind",
        type=Type(
            cxx_name="RequiresExpressionIndentationKind",
            yaml_name="RequiresExpressionIndentationKind",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="REI_OuterScope", config="REI_OuterScope"),
            EnumValue(name="REI_Keyword", config="REI_Keyword"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="SeparateDefinitionBlocks",
    type=Type(
        cxx_name="SeparateDefinitionStyle",
        yaml_name="SeparateDefinitionStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=14, minor=None),
    enum=Enum(
        name="SeparateDefinitionStyle",
        type=Type(
            cxx_name="SeparateDefinitionStyle",
            yaml_name="SeparateDefinitionStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="SDS_Leave", config="SDS_Leave"),
            EnumValue(name="SDS_Always", config="SDS_Always"),
            EnumValue(name="SDS_Never", config="SDS_Never"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="ShortNamespaceLines",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=13, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SkipMacroDefinitionBody",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=18, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SortIncludes",
    type=Type(
        cxx_name="SortIncludesOptions",
        yaml_name="SortIncludesOptions",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=3, minor=8),
    enum=None,
    nested_struct=NestedStruct(
        name="SortIncludesOptions",
        type=Type(
            cxx_name="SortIncludesOptions",
            yaml_name="SortIncludesOptions",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Enabled",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="IgnoreCase",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="IgnoreExtension",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="SortJavaStaticImport",
    type=Type(
        cxx_name="SortJavaStaticImportOptions",
        yaml_name="SortJavaStaticImportOptions",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=12, minor=None),
    enum=Enum(
        name="SortJavaStaticImportOptions",
        type=Type(
            cxx_name="SortJavaStaticImportOptions",
            yaml_name="SortJavaStaticImportOptions",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="SJSIO_Before", config="SJSIO_Before"),
            EnumValue(name="SJSIO_After", config="SJSIO_After"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="SortUsingDeclarations",
    type=Type(
        cxx_name="SortUsingDeclarationsOptions",
        yaml_name="SortUsingDeclarationsOptions",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=5, minor=None),
    enum=Enum(
        name="SortUsingDeclarationsOptions",
        type=Type(
            cxx_name="SortUsingDeclarationsOptions",
            yaml_name="SortUsingDeclarationsOptions",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="SUD_Never", config="SUD_Never"),
            EnumValue(name="SUD_Lexicographic", config="SUD_Lexicographic"),
            EnumValue(name="SUD_LexicographicNumeric", config="SUD_LexicographicNumeric"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="SpaceAfterCStyleCast",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=5),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceAfterLogicalNot",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=9, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceAfterOperatorKeyword",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=21, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceAfterTemplateKeyword",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=4, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceAroundPointerQualifiers",
    type=Type(
        cxx_name="SpaceAroundPointerQualifiersStyle",
        yaml_name="SpaceAroundPointerQualifiersStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=12, minor=None),
    enum=Enum(
        name="SpaceAroundPointerQualifiersStyle",
        type=Type(
            cxx_name="SpaceAroundPointerQualifiersStyle",
            yaml_name="SpaceAroundPointerQualifiersStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="SAPQ_Default", config="SAPQ_Default"),
            EnumValue(name="SAPQ_Before", config="SAPQ_Before"),
            EnumValue(name="SAPQ_After", config="SAPQ_After"),
            EnumValue(name="SAPQ_Both", config="SAPQ_Both"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="SpaceBeforeAssignmentOperators",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceBeforeCaseColon",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=12, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceBeforeCpp11BracedList",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=7, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceBeforeCtorInitializerColon",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=7, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceBeforeInheritanceColon",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=7, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceBeforeJsonColon",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=17, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceBeforeParens",
    type=Type(
        cxx_name="SpaceBeforeParensStyle",
        yaml_name="SpaceBeforeParensStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=True,
    ),
    version=Version(major=3, minor=5),
    enum=Enum(
        name="SpaceBeforeParensStyle",
        type=Type(
            cxx_name="SpaceBeforeParensStyle",
            yaml_name="SpaceBeforeParensStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=True,
        ),
        values=[
            EnumValue(name="SBPO_Never", config="SBPO_Never"),
            EnumValue(name="SBPO_ControlStatements", config="SBPO_ControlStatements"),
            EnumValue(
                name="SBPO_ControlStatementsExceptControlMacros", config="SBPO_ControlStatementsExceptControlMacros"
            ),
            EnumValue(name="SBPO_NonEmptyParentheses", config="SBPO_NonEmptyParentheses"),
            EnumValue(name="SBPO_Always", config="SBPO_Always"),
            EnumValue(name="SBPO_Custom", config="SBPO_Custom"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="SpaceBeforeParensOptions",
    type=Type(
        cxx_name="SpaceBeforeParensCustom",
        yaml_name="SpaceBeforeParensCustom",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=14, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="SpaceBeforeParensCustom",
        type=Type(
            cxx_name="SpaceBeforeParensCustom",
            yaml_name="SpaceBeforeParensCustom",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="AfterControlStatements",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterForeachMacros",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterFunctionDeclarationName",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterFunctionDefinitionName",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterIfMacros",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterNot",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterOverloadedOperator",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterPlacementOperator",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterRequiresInClause",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="AfterRequiresInExpression",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="BeforeNonEmptyParentheses",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="SpaceBeforeRangeBasedForLoopColon",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=7, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceBeforeSquareBrackets",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=10, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceInEmptyBlock",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=10, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpaceInEmptyBraces",
    type=Type(
        cxx_name="SpaceInEmptyBracesStyle",
        yaml_name="SpaceInEmptyBracesStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=22, minor=None),
    enum=Enum(
        name="SpaceInEmptyBracesStyle",
        type=Type(
            cxx_name="SpaceInEmptyBracesStyle",
            yaml_name="SpaceInEmptyBracesStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="SIEB_Always", config="SIEB_Always"),
            EnumValue(name="SIEB_Block", config="SIEB_Block"),
            EnumValue(name="SIEB_Never", config="SIEB_Never"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="SpaceInEmptyParentheses",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpacesBeforeTrailingComments",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
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

Option(
    name="SpacesInCStyleCastParentheses",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpacesInConditionalStatement",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=10, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpacesInContainerLiterals",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpacesInLineCommentPrefix",
    type=Type(
        cxx_name="SpacesInLineComment",
        yaml_name="SpacesInLineComment",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=13, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="SpacesInLineComment",
        type=Type(
            cxx_name="SpacesInLineComment",
            yaml_name="SpacesInLineComment",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="Minimum",
                type=Type(
                    cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False
                ),
                version=None,
            ),
            NestedField(
                name="Maximum",
                type=Type(
                    cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False
                ),
                version=None,
            ),
        ],
    ),
)

Option(
    name="SpacesInParens",
    type=Type(
        cxx_name="SpacesInParensStyle",
        yaml_name="SpacesInParensStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=17, minor=None),
    enum=Enum(
        name="SpacesInParensStyle",
        type=Type(
            cxx_name="SpacesInParensStyle",
            yaml_name="SpacesInParensStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[EnumValue(name="SIPO_Never", config="SIPO_Never"), EnumValue(name="SIPO_Custom", config="SIPO_Custom")],
    ),
    nested_struct=None,
)

Option(
    name="SpacesInParensOptions",
    type=Type(
        cxx_name="SpacesInParensCustom",
        yaml_name="SpacesInParensCustom",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=17, minor=None),
    enum=None,
    nested_struct=NestedStruct(
        name="SpacesInParensCustom",
        type=Type(
            cxx_name="SpacesInParensCustom",
            yaml_name="SpacesInParensCustom",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            NestedField(
                name="ExceptDoubleParentheses",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="InConditionalStatements",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="InCStyleCasts",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="InEmptyParentheses",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
            NestedField(
                name="Other",
                type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
                version=None,
            ),
        ],
    ),
)

Option(
    name="SpacesInParentheses",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="SpacesInSquareBrackets",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="Standard",
    type=Type(
        cxx_name="LanguageStandard", yaml_name="LanguageStandard", is_list=False, is_optional=False, is_deprecated=False
    ),
    version=Version(major=3, minor=7),
    enum=Enum(
        name="LanguageStandard",
        type=Type(
            cxx_name="LanguageStandard",
            yaml_name="LanguageStandard",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="LS_Cpp03", config="c++03"),
            EnumValue(name="LS_Cpp11", config="c++11"),
            EnumValue(name="LS_Cpp14", config="c++14"),
            EnumValue(name="LS_Cpp17", config="c++17"),
            EnumValue(name="LS_Cpp20", config="c++20"),
            EnumValue(name="LS_Latest", config="LS_Latest"),
            EnumValue(name="LS_Auto", config="LS_Auto"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="StatementAttributeLikeMacros",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=12, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="StatementMacros",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=8, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="TabWidth",
    type=Type(cxx_name="unsigned", yaml_name="Unsigned", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=None,
    nested_struct=None,
)

Option(
    name="TableGenBreakInsideDAGArg",
    type=Type(cxx_name="DAGArgStyle", yaml_name="DAGArgStyle", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=19, minor=None),
    enum=Enum(
        name="DAGArgStyle",
        type=Type(
            cxx_name="DAGArgStyle", yaml_name="DAGArgStyle", is_list=False, is_optional=False, is_deprecated=False
        ),
        values=[
            EnumValue(name="DAS_DontBreak", config="DAS_DontBreak"),
            EnumValue(name="DAS_BreakElements", config="DAS_BreakElements"),
            EnumValue(name="DAS_BreakAll", config="DAS_BreakAll"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="TableGenBreakingDAGArgOperators",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=19, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="TemplateNames",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=20, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="TypeNames",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=17, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="TypenameMacros",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=9, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="UseCRLF",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=10, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="UseTab",
    type=Type(cxx_name="UseTabStyle", yaml_name="UseTabStyle", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=3, minor=7),
    enum=Enum(
        name="UseTabStyle",
        type=Type(
            cxx_name="UseTabStyle", yaml_name="UseTabStyle", is_list=False, is_optional=False, is_deprecated=False
        ),
        values=[
            EnumValue(name="UT_Never", config="UT_Never"),
            EnumValue(name="UT_ForIndentation", config="UT_ForIndentation"),
            EnumValue(name="UT_ForContinuationAndIndentation", config="UT_ForContinuationAndIndentation"),
            EnumValue(name="UT_AlignWithSpaces", config="UT_AlignWithSpaces"),
            EnumValue(name="UT_Always", config="UT_Always"),
        ],
    ),
    nested_struct=None,
)

Option(
    name="VariableTemplates",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=20, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="VerilogBreakBetweenInstancePorts",
    type=Type(cxx_name="bool", yaml_name="Boolean", is_list=False, is_optional=False, is_deprecated=False),
    version=Version(major=17, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="WhitespaceSensitiveMacros",
    type=Type(
        cxx_name="std::vector<std::string>",
        yaml_name="List of Strings",
        is_list=True,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=11, minor=None),
    enum=None,
    nested_struct=None,
)

Option(
    name="WrapNamespaceBodyWithEmptyLines",
    type=Type(
        cxx_name="WrapNamespaceBodyWithEmptyLinesStyle",
        yaml_name="WrapNamespaceBodyWithEmptyLinesStyle",
        is_list=False,
        is_optional=False,
        is_deprecated=False,
    ),
    version=Version(major=20, minor=None),
    enum=Enum(
        name="WrapNamespaceBodyWithEmptyLinesStyle",
        type=Type(
            cxx_name="WrapNamespaceBodyWithEmptyLinesStyle",
            yaml_name="WrapNamespaceBodyWithEmptyLinesStyle",
            is_list=False,
            is_optional=False,
            is_deprecated=False,
        ),
        values=[
            EnumValue(name="WNBWELS_Never", config="WNBWELS_Never"),
            EnumValue(name="WNBWELS_Always", config="WNBWELS_Always"),
            EnumValue(name="WNBWELS_Leave", config="WNBWELS_Leave"),
        ],
    ),
    nested_struct=None,
)
