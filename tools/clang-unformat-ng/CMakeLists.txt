find_package(fmt REQUIRED CONFIG)
message(STATUS "Found fmt ${FMT_PACKAGE_VERSION}")
message(STATUS "Using fmt-config.cmake in ${FMT_DIR}")
list(APPEND CMAKE_MODULE_PATH ${FMT_CMAKE_DIR})

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in ${LLVM_DIR}")
list(APPEND CMAKE_MODULE_PATH ${LLVM_CMAKE_DIR})

find_package(Clang REQUIRED CONFIG)
message(STATUS "Found Clang ${Clang_PACKAGE_VERSION}")
message(STATUS "Using ClangConfig.cmake in ${Clang_DIR}")
list(APPEND CMAKE_MODULE_PATH ${CLANG_CMAKE_DIR})
include(AddClang)

add_executable(clang-unformat-ng unformat.cpp)
target_include_directories(clang-unformat-ng PRIVATE ${CLANG_INCLUDE_DIRS})
target_link_libraries(clang-unformat-ng PRIVATE fmt::fmt LLVMSupport clangTooling clangFormat)

set_target_properties(clang-unformat-ng PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS ON
    CXX_STANDARD_REQUIRED ON
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

install(TARGETS clang-unformat-ng)
