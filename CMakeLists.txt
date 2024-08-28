cmake_minimum_required(VERSION 3.21)
project(Nuclear)

set(CMAKE_CXX_STANDARD 20)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(LLVM 18 REQUIRED
    core orcjit
)

add_library(nuked STATIC)
add_subdirectory(src)
add_subdirectory(test)

target_include_directories(nuked PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_directories(nuked PRIVATE ${LLVM_LIBRARY_DIRS})
target_link_libraries(nuked PRIVATE ${LLVM_LIBRARIES})