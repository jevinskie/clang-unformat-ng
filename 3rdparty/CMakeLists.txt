add_subdirectory(fmt EXCLUDE_FROM_ALL)

option(REFLECTCPP_USE_STD_EXPECTED "Use std::expected instead of the built-in Result type (requires C++-23)" ON)
add_subdirectory(reflect-cpp EXCLUDE_FROM_ALL)
