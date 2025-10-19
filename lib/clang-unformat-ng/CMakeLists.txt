find_package(LLVM REQUIRED CONFIG GLOBAL)
message(STATUS "libunformat: Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "libunformat: Using LLVMConfig.cmake in ${LLVM_DIR}")

find_package(Clang REQUIRED CONFIG GLOBAL)
message(STATUS "libunformat: Found Clang ${Clang_PACKAGE_VERSION}")
message(STATUS "libunformat: Using ClangConfig.cmake in ${Clang_DIR}")

set(LIBUNFMTNG_SRC
    core.cpp
    fmt.cpp
    style.cpp
    utils.cpp
)

set(LIBUNFMTNG_HDR_STANDALONE
    clang-unformat-ng.hpp
)

set(LIBUNFMTNG_HDR_STANDALONE_PRIVATE
    common-internal.hpp
)

set(LIBUNFMTNG_HDR)
foreach(HDR ${LIBUNFMTNG_HDR_STANDALONE})
    set(RELHDR "${CMAKE_CURRENT_SOURCE_DIR}/../../include/clang-unformat-ng/${HDR}")
    if(NOT EXISTS ${RELHDR})
        message(ERROR "LIBUNFMTNG_HDR_STANDALONE missing: ${HDR} ${RELHDR}")
    endif()
    list(APPEND LIBUNFMTNG_HDR ${RELHDR})
endforeach()

foreach(HDR ${LIBUNFMTNG_HDR_STANDALONE_PRIVATE})
    set(RELHDR "${CMAKE_CURRENT_SOURCE_DIR}/${HDR}")
    if(NOT EXISTS ${RELHDR})
        message(ERROR "LIBUNFMTNG_HDR_STANDALONE_PRIVATE missing: ${HDR} ${RELHDR}")
    endif()
    list(APPEND LIBUNFMTNG_HDR ${RELHDR})
endforeach()

foreach(SRC ${LIBUNFMTNG_SRC})
    get_filename_component(HDR_NAME ${SRC} NAME_WLE)
    set(HDR "${CMAKE_CURRENT_SOURCE_DIR}/../../include/clang-unformat-ng/${HDR_NAME}.hpp")
    if(EXISTS ${HDR})
        list(APPEND LIBUNFMTNG_HDR ${HDR})
    endif()
endforeach()

set(LIBUNFMTNG_PUBLIC_LIBS
    fmt::fmt
    stringzilla_header
)

set(LIBUNFMTNG_PRIVATE_LIBS
    # LLVM
    LLVMSupport
    # Clang
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
    clangTransformer
    # etc
    reflectcpp
    enchantum::enchantum
    effolkronium_random
    nlohmann_json::nlohmann_json
)

# LIBUNFMTNG_HDR added for IDE project generation
add_library(clang-unformat-ng ${LIBUNFMTNG_SRC} ${LIBUNFMTNG_HDR})
set_target_properties(clang-unformat-ng PROPERTIES PUBLIC_HEADER "${LIBUNFMTNG_HDR}")
target_compile_options(clang-unformat-ng PRIVATE -fno-rtti)
target_link_libraries(clang-unformat-ng
PUBLIC
    ${LIBUNFMTNG_PUBLIC_LIBS}
PRIVATE
    ${LIBUNFMTNG_PRIVATE_LIBS}
)

target_include_directories(clang-unformat-ng
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${CLANG_INCLUDE_DIRS}
)

set_target_properties(clang-unformat-ng PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS ON
    CXX_STANDARD_REQUIRED ON
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

add_subdirectory(python)
