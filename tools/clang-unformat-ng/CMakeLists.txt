# find_package(LLVM REQUIRED CONFIG)
# message(STATUS "Tool: Found LLVM ${LLVM_PACKAGE_VERSION}")
# message(STATUS "Tool: Using LLVMConfig.cmake in ${LLVM_DIR}")
# list(APPEND CMAKE_MODULE_PATH ${LLVM_CMAKE_DIR})

# find_package(Clang REQUIRED CONFIG)
# message(STATUS "Tool: Found Clang ${Clang_PACKAGE_VERSION}")
# message(STATUS "Tool: Using ClangConfig.cmake in ${Clang_DIR}")


add_executable(unformat unformat.cpp)
target_compile_options(unformat PRIVATE ${JEV_COLOR_DIAGS} -fno-rtti)
target_include_directories(unformat PRIVATE ${CLANG_INCLUDE_DIRS})
target_link_libraries(unformat PRIVATE
    fmt::fmt
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
    clangTransformer
    clang-unformat-ng
)

set_target_properties(unformat PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS ON
    CXX_STANDARD_REQUIRED ON
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

install(TARGETS unformat)
