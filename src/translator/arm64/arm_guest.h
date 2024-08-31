#pragma once

#include <instruction.h>
#include <translator/preset.h>
namespace nuclear::translator::arm64 {
    class ArmGuest : public Preset {
    public:
        ArmGuest() = default;

        void readNextInstruction() override;
        void reset() override;
    protected:
        FetchResult current{};
    };
}
