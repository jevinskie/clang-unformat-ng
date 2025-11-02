if (NOT UNFMTNG_DISABLE_LLVM)
    find_package(LLVM REQUIRED CONFIG GLOBAL)
    message(STATUS "unformat: Found LLVM ${LLVM_PACKAGE_VERSION}")
    message(STATUS "unformat: Using LLVMConfig.cmake in ${LLVM_DIR}")

    find_package(Clang REQUIRED CONFIG GLOBAL)
    message(STATUS "unformat: Found Clang ${Clang_PACKAGE_VERSION}")
    message(STATUS "unformat: Using ClangConfig.cmake in ${Clang_DIR}")
endif()

set(UNFMTNG_SRC
    unformat.cpp
)

set(UNFMTNG_PUBLIC_LIBS
)

set(UNFMTNG_PRIVATE_LIBS
    clang-unformat-ng
    fmt::fmt
    reflectcpp
    flags
)
if (NOT UNFMTNG_DISABLE_LLVM)
list(APPEND UNFMTNG_PRIVATE_LIBS
    LLVMSupport
)
endif()

# UNFMTNG_HDR added for IDE project generation
add_executable(unformat-ng ${UNFMTNG_SRC})

target_compile_options(unformat-ng PRIVATE -fno-rtti)
target_link_libraries(unformat-ng
PUBLIC
    ${UNFMTNG_PUBLIC_LIBS}
PRIVATE
    ${UNFMTNG_PRIVATE_LIBS}
)

target_include_directories(unformat-ng
    PRIVATE ${LLVM_INCLUDE_DIRS}
)

set_target_properties(unformat-ng PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS ON
    CXX_STANDARD_REQUIRED ON
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

install(TARGETS unformat-ng)
