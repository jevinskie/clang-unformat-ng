set(Python_FIND_UNVERSIONED_NAMES FIRST)
set(Python_FIND_STRATEGY LOCATION)
find_package(Python COMPONENTS Interpreter Development REQUIRED)

nanobind_add_module(cxx_py_ffi NB_STATIC cxx_py_ffi.cpp)
target_link_libraries(cxx_py_ffi PRIVATE clang-unformat-ng)
