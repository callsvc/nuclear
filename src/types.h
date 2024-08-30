#pragma once
#include <cstdint>

namespace nuclear {
    enum CodeGenMode {
        Arm86,
        Arm3286,
        MipsArm,
        Mips86
    };
    inline auto isArm(const CodeGenMode mode) {
        return mode == Arm86 || mode == Arm3286;
    }

    using u8 = std::uint8_t;
    using u16 = std::uint16_t;
    using u32 = std::uint32_t;
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;

    using f32 = float;
    using f64 = double;

    using AddrInt = uintptr_t;
}