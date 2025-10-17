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
    clangTransformer
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
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${CLANG_INCLUDE_DIRS}
)

set_target_properties(unformat PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS ON
    CXX_STANDARD_REQUIRED ON
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)
