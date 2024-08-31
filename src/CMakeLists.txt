cmake_minimum_required(VERSION 3.21)

target_sources(nuked PRIVATE
    emitter/code_blocks.cpp
    emitter/code_blocks.h
    emitter/allocate.cpp
    emitter/allocate.h
    emitter/x86/gen64.cpp
    emitter/x86/gen64.h
    translator/preset.cpp
    translator/preset.h
    translator/arm_types.h
    translator/arm64/arm_guest.cpp
    translator/arm64/arm_guest.h

    arm_context.cpp
    arm_context.h
    jit_eastwood.h
    jit_eastwood.cpp
    instruction.h
    types.h
)

target_include_directories(nuked PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:>
)