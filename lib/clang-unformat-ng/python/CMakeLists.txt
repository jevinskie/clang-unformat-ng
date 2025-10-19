set(Python_FIND_UNVERSIONED_NAMES FIRST)
set(Python_FIND_STRATEGY LOCATION)
find_package(Python COMPONENTS Interpreter Development REQUIRED)

nanobind_add_module(cxx_py NB_STATIC cxx_py.cpp)
target_link_libraries(cxx_py PRIVATE clang-unformat-ng)

nanobind_add_stub(
    cxx_py_stub
    MODULE cxx_py
    OUTPUT cxx_py.pyi
    PYTHON_PATH $<TARGET_FILE_DIR:cxx_py>
    DEPENDS cxx_py
)
