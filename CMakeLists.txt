cmake_minimum_required(VERSION 4.1)

project(clang-unformat-ng C CXX)

option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." ON)

if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       set(JEV_COLOR_DIAGS -fdiagnostics-color=always)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
       set(JEV_COLOR_DIAGS -fcolor-diagnostics)
    else()
        message(WARNING "COLOR_DIAGS: Compiler not detected: ${CMAKE_CXX_COMPILER_ID}")
        set(JEV_COLOR_DIAGS)
    endif ()
endif ()

# needed on linux to build exe w/ object library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_options(${JEV_COLOR_DIAGS})
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
# add_compile_options(-fsanitize=thread)
# add_link_options(-fsanitize=thread)
# add_compile_options(-fsanitize=undefined)
# add_link_options(-fsanitize=undefined)

add_subdirectory(3rdparty)
add_subdirectory(lib)
add_subdirectory(tools)
