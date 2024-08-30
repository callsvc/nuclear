#include <emitter/allocate.h>
#include <arm_context.h>

namespace nuclear {
    using namespace emitter;
    ArmContext::ArmContext(std::vector<u8>& content) : memory(content) {
        allocateCpuRegisters(true);
        ArmGuest::reset();
        Gen64::reset();
    }

    u64 ArmContext::executeNext() {
        if (!runInstruction(armCpu->ir)) {
            readNextInstruction();
            cacheAndRunInstruction(armCpu->ir, current);
        }

        return 1;
    }

    u8 ArmContext::readMemory8(const AddrInt address) {
        return memory[address];
    }
    u16 ArmContext::readMemory16(const AddrInt address) {
        u16 result{readMemory8(address)};
        result |= readMemory8(address + 1) << 8;
        return result;
    }
    u32 ArmContext::readMemory32(const AddrInt address) {
        u32 result{readMemory16(address)};
        result |= readMemory16(address + 2) << 16;
        return result;
    }
}
