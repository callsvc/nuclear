#include <unordered_map>
#include <translator/arm64/arm_guest.h>
#include <emitter/allocate.h>

namespace nuclear::translator::arm64 {
    using namespace emitter;

    void ArmGuest::reset() {
        current = {};
        if (armCpu->ir != 0)
            armCpu->ir = {};
    }

    void ArmGuest::readNextInstruction() {
        if (!armCpu)
            return;
        const auto instruction{readMemory32(armCpu->ir)};
        armCpu->ir += 4;

        static std::unordered_map<u32, Instruction> modulize;
        if (modulize.empty()) {
            modulize[0xd2800000] = Mov;
            modulize[0x8b000000] = Add;
            modulize[0xd69f03e0] = Ret;
        }

        decltype(current.operation) op{};
        const auto byUpperbytes{instruction & 0xfff00000};
        if (runtime32lookup.contains(byUpperbytes)) {
            op = modulize[byUpperbytes];
        }
        (void)op;
    }
}
