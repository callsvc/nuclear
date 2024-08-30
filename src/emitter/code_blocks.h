#pragma once
#include <vector>

#include <instruction.h>
namespace nuclear::emitter {
    struct JitBlock {
        u64 basePc;
        bool dirty;
    };

    class CodeBlocks {
    public:
        virtual ~CodeBlocks() = default;

        CodeBlocks() = default;
        [[nodiscard]] bool isPresent(u64 pc) const;
        [[nodiscard]] bool runInstruction(u64 pc) const;
        void cacheAndRunInstruction(u64 pc, FetchResult& fetched);

        virtual void reset() = 0;
    protected:
        std::vector<JitBlock> regions;
    };
}
