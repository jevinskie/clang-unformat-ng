set(LIBUNFMTNG_SRC
    utils.cpp
)

set(LIBUNFMTNG_HDR_STANDALONE
    clang-unformat-ng.hpp
)

set(LIBUNFMTNG_HDR_STANDALONE_PRIVATE
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
)

set(LIBUNFMTNG_PRIVATE_LIBS
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

# LIBUNFMTNG_HDR added for IDE project generation
add_library(clang-unformat-ng ${LIBUNFMTNG_SRC} ${LIBUNFMTNG_HDR})
set_target_properties(clang-unformat-ng PROPERTIES PUBLIC_HEADER "${LIBUNFMTNG_HDR}")

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
