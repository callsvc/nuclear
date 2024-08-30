#include <stdexcept>
#include <emitter/code_blocks.h>

namespace nuclear::emitter {
    bool CodeBlocks::isPresent(const u64 pc) const {
        auto isPcCompiled = [&](const JitBlock& block) -> bool {
            if (!block.dirty)
                if (block.basePc == pc & 4096)
                    return true;
            return {};
        };
        return std::ranges::find_if(regions, isPcCompiled) != std::ranges::end(regions);
    }
    bool CodeBlocks::runInstruction(const u64 pc) const {
        if (!isPresent(pc))
            return {};
        return true;
    }

    void CodeBlocks::cacheAndRunInstruction(u64 pc, [[maybe_unused]] FetchResult& fetched) {
        regions.emplace_back(pc);

        if (!runInstruction(pc)) {
            throw std::runtime_error("Failed to execute instruction");
        }
    }
}
