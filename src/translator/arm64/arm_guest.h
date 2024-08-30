#pragma once

#include <instruction.h>

#include <translator/ir.h>
namespace nuclear::translator::arm64 {
    class ArmGuest : public Ir {
    public:
        ArmGuest() = default;
        void emitterAdd(u32 opcode);

        void readNextInstruction() override;
        void reset() override;
    protected:
        FetchResult current{};
    };
}
