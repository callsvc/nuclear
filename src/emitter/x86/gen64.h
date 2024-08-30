#pragma once

#include <types.h>

#include <emitter/code_blocks.h>
namespace nuclear::emitter::x86 {
    class Gen64 : public CodeBlocks {
    public:
        Gen64() = default;
        void reset() override;

        virtual u64 executeNext() = 0;
    };
}
