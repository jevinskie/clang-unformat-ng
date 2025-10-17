find_package(LLVM REQUIRED CONFIG GLOBAL)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in ${LLVM_DIR}")
# FIXME: Needed?
list(APPEND CMAKE_MODULE_PATH ${LLVM_CMAKE_DIR})

find_package(Clang REQUIRED CONFIG GLOBAL)
message(STATUS "Found Clang ${Clang_PACKAGE_VERSION}")
message(STATUS "Using ClangConfig.cmake in ${Clang_DIR}")
# FIXME: Needed?
list(APPEND CMAKE_MODULE_PATH ${CLANG_CMAKE_DIR})

message(WARNING "fuck ${CLANG_INCLUDE_DIRS}")
# set(CLANG_INCLUDE_DIRS FORCE PARENT_DIRECTORY "${CLANG_INCLUDE_DIRS}")
# message(WARNING "fuck-post ${CLANG_INCLUDE_DIRS}")

set(UNFMTNG_SRC
    unformat.cpp
)

set(UNFMTNG_PUBLIC_LIBS
)

set(UNFMTNG_PRIVATE_LIBS
    clang-unformat-ng
    fmt::fmt
    reflect-cpp
    LLVMSupport
    clangAST
    clangASTMatchers
    clangBasic
    clangFrontend
    clangFormat
    clangHandleCXX
    clangRewrite
    clangSerialization
    clangTooling
    clangToolingCore
    clangToolingRefactoring
)

# UNFMTNG_HDR added for IDE project generation
add_library(unformat ${UNFMTNG_SRC})

target_link_libraries(unformat
PUBLIC
    ${UNFMTNG_PUBLIC_LIBS}
PRIVATE
    ${UNFMTNG_PRIVATE_LIBS}
)

target_include_directories(unformat
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${CLANG_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)
message(WARNING "fuck ${CLANG_INCLUDE_DIRS}")

set_target_properties(unformat PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS ON
    CXX_STANDARD_REQUIRED ON
    # CXX_VISIBILITY_PRESET hidden
    # VISIBILITY_INLINES_HIDDEN ON
)
