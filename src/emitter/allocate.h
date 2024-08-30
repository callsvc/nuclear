#pragma once
#include <array>

#include <translator/arm_types.h>
namespace nuclear::emitter {
    namespace a64 = translator;

    struct alignas(4096) ArmCpu {
        std::array<a64::RegisterInt, 32> registers{};
        std::array<a64::Scalar, 32> scalars{};

        a64::RegisterInt ir{};
    };

    inline ArmCpu* armCpu{nullptr};
    void allocateCpuRegisters(bool isArm);
}
