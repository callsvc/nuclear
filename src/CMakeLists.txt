cmake_minimum_required(VERSION 3.21)

target_sources(nuked PRIVATE
    module.cpp
)
target_sources(nuked PUBLIC
    module.h
)

target_include_directories(nuked PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:>
)