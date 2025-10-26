#  Build

```console
cmake --fresh -W Dev -G Ninja .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_INSTALL_PREFIX=$(greadlink -f ../../prefix) -DCMAKE_PREFIX_PATH="$HOME/code/llvm/tot/tot-dbg/prefix/lib/cmake/llvm;$HOME/code/llvm/tot/tot-dbg/prefix/lib/cmake/clang;/opt/homebrew/opt/fmt/lib/cmake;/opt/homebrew/opt/boost/lib/cmake" -DCMAKE_EXE_LINKER_FLAGS="-fuse-ld=lld" -DCMAKE_MODULE_LINKER_FLAGS="-fuse-ld=lld" -DPython_ROOT_DIR=$(pyenv prefix)
```

# Run

```console
In [1]: import socket
In [2]: s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
In [3]: s2 = s.connect("/tmp/unformat.sock")
```

# FormatStyle options

## Example: SpacesInAnglesStyle

### Clang upstream
```c++
enum SpacesInAnglesStyle : int8_t {
  SIAS_Never,
  SIAS_Always,
  SIAS_Leave
};
SpacesInAnglesStyle SpacesInAngles;
```

### clang_unformat_ng.styleopts.data
```python
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
),
```
