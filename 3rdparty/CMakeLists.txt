

set(Python_FIND_UNVERSIONED_NAMES FIRST)
set(Python_FIND_STRATEGY LOCATION)
find_package(Python COMPONENTS Interpreter Development REQUIRED GLOBAL)

add_subdirectory(nanobind EXCLUDE_FROM_ALL)

add_subdirectory(fmt EXCLUDE_FROM_ALL)

add_subdirectory(enchantum EXCLUDE_FROM_ALL)

option(REFLECTCPP_USE_STD_EXPECTED "Use std::expected instead of the built-in Result type (requires C++-23)" ON)
add_subdirectory(reflect-cpp EXCLUDE_FROM_ALL)

add_subdirectory(random EXCLUDE_FROM_ALL)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(json EXCLUDE_FROM_ALL)

add_subdirectory(StringZilla EXCLUDE_FROM_ALL)

add_library(thread-pool INTERFACE)
target_include_directories(thread-pool INTERFACE thread-pool/include)

add_subdirectory(strong_type EXCLUDE_FROM_ALL)

add_subdirectory(flags EXCLUDE_FROM_ALL)

find_package(Boost REQUIRED COMPONENTS headers CONFIG GLOBAL)
# TODO: figure out what this is supposed to do
set_target_properties(Boost::headers PROPERTIES IMPORTED_GLOBAL ON)

add_subdirectory(leaf EXCLUDE_FROM_ALL)
