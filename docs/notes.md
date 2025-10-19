#  Build

```console
cmake --fresh -W Dev -G Ninja .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_INSTALL_PREFIX=$(greadlink -f ../../prefix) -DCMAKE_PREFIX_PATH="$HOME/code/llvm/tot/tot-dbg/prefix/lib/cmake/llvm;$HOME/code/llvm/tot/tot-dbg/prefix/lib/cmake/clang;/opt/homebrew/opt/fmt/lib/cmake" -DCMAKE_EXE_LINKER_FLAGS="-fuse-ld=lld" -DCMAKE_MODULE_LINKER_FLAGS="-fuse-ld=lld" -DPython_ROOT_DIR=$(pyenv prefix)
```
