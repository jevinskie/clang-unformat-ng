# find_package(LLVM REQUIRED CONFIG GLOBAL)
# message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
# message(STATUS "Using LLVMConfig.cmake in ${LLVM_DIR}")
# # FIXME: Needed?
# list(APPEND CMAKE_MODULE_PATH ${LLVM_CMAKE_DIR})

# find_package(Clang REQUIRED CONFIG GLOBAL)
# message(STATUS "Found Clang ${Clang_PACKAGE_VERSION}")
# message(STATUS "Using ClangConfig.cmake in ${Clang_DIR}")
# # FIXME: Needed?
# list(APPEND CMAKE_MODULE_PATH ${CLANG_CMAKE_DIR})

# message(WARNING "fuckfuck ${CLANG_INCLUDE_DIRS}")
# set(CLANG_INCLUDE_DIRS FORCE PARENT_DIRECTORY "${CLANG_INCLUDE_DIRS}")
# message(WARNING "fuckfuck-post ${CLANG_INCLUDE_DIRS}")

add_subdirectory(fmt EXCLUDE_FROM_ALL)
add_subdirectory(reflect-cpp EXCLUDE_FROM_ALL)
