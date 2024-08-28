cmake_minimum_required(VERSION 3.21)
add_executable(codegen codegen.cpp)
target_link_libraries(codegen PRIVATE nuked)