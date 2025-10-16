include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        12.0.0)
FetchContent_MakeAvailable(fmt)

# find_package(fmt REQUIRED CONFIG GLOBAL)
# message(STATUS "Found fmt ${FMT_PACKAGE_VERSION}")
# message(STATUS "Using fmt-config.cmake in ${FMT_DIR}")
# list(APPEND CMAKE_MODULE_PATH ${FMT_CMAKE_DIR})

find_package(LLVM REQUIRED CONFIG GLOBAL)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in ${LLVM_DIR}")
list(APPEND CMAKE_MODULE_PATH ${LLVM_CMAKE_DIR})

find_package(Clang REQUIRED CONFIG GLOBAL)
message(STATUS "Found Clang ${Clang_PACKAGE_VERSION}")
message(STATUS "Using ClangConfig.cmake in ${Clang_DIR}")
list(APPEND CMAKE_MODULE_PATH ${CLANG_CMAKE_DIR})
