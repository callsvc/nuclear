cmake_minimum_required(VERSION 3.21)
add_executable(arm-add arm_add.cpp)
target_link_libraries(arm-add PRIVATE nuked)