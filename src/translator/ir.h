#pragma once

#include <types.h>
namespace nuclear::translator {
    class Ir {
    public:
        virtual ~Ir() = default;

        virtual void readNextInstruction() = 0;
        virtual u8 readMemory8(AddrInt address) = 0;
        virtual u16 readMemory16(AddrInt address) = 0;
        virtual u32 readMemory32(AddrInt address) = 0;

        virtual void reset() = 0;
    };
}