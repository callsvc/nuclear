#pragma once

#include <translator/arm64/arm_guest.h>
#include <emitter/x86/gen64.h>
namespace nuclear {
    class ArmContext final : translator::arm64::ArmGuest, emitter::x86::Gen64 {
    public:
        explicit ArmContext(std::vector<u8>& content);

        u64 executeNext() override;

        u8 readMemory8(AddrInt address) override;
        u16 readMemory16(AddrInt address) override;
        u32 readMemory32(AddrInt address) override;
    private:
        std::vector<u8>& memory;
    };
}
