set(Python_FIND_UNVERSIONED_NAMES FIRST)
set(Python_FIND_STRATEGY LOCATION)
find_package(Python COMPONENTS Interpreter Development REQUIRED)

nanobind_add_module(clang_unformat_ng_py_ffi NB_STATIC python.cpp)
# target_link_libraries(clang_unformat_ng_py_ffi PRIVATE)
