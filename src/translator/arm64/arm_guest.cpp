#include <unordered_map>

#include <translator/arm64/arm_guest.h>
#include <emitter/allocate.h>
namespace nuclear::translator::arm64 {
    using namespace emitter;

    std::unordered_map<u32, Instruction> r64Table{
        {0x8b, Add},
    };

    void ArmGuest::emitterAdd(const u32 opcode) {
        for (u32 dest{}; dest < 2; dest++) {
            current.params.emplace_back(opcode >> 16 - dest * 8 & 0xff, dest, true);
        }
        current.params.emplace_back(opcode & 0xff, 2, false);
    }

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

        decltype(current.operation) op{};
        if (r64Table.contains(instruction >> 24)) {
            op = current.operation = r64Table.at(instruction >> 24);
        }
        if (op == Add) {
            emitterAdd(instruction);
        }
    }
}
