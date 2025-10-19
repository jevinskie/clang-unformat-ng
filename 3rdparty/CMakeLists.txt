
# message(WARNING "pre my Python3 find")
# set(Python3_FIND_UNVERSIONED_NAMES FIRST)
# set(Python3_FIND_STRATEGY LOCATION)
# find_package(Python3 3.11 COMPONENTS Development)
# message(WARNING "post my Python3 find")

message(WARNING "pre my Python find")
set(Python_FIND_UNVERSIONED_NAMES FIRST)
set(Python_FIND_STRATEGY LOCATION)
find_package(Python COMPONENTS Interpreter Development REQUIRED GLOBAL)
message(WARNING "post my Python find")

add_subdirectory(nanobind EXCLUDE_FROM_ALL)

add_subdirectory(fmt EXCLUDE_FROM_ALL)

add_subdirectory(enchantum EXCLUDE_FROM_ALL)

option(REFLECTCPP_USE_STD_EXPECTED "Use std::expected instead of the built-in Result type (requires C++-23)" ON)
add_subdirectory(reflect-cpp EXCLUDE_FROM_ALL)

add_subdirectory(random EXCLUDE_FROM_ALL)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(json EXCLUDE_FROM_ALL)
