#pragma once
#include <vector>
#include <memory>

#include <arm_context.h>
namespace nuclear {
    class JitEastWood {
    public:
        JitEastWood(CodeGenMode mode, std::vector<u8>& content);

        u64 execute();
        void addCycles(const u64 total) {
            cyclesCount += total;
        }
    private:
        std::unique_ptr<ArmContext> arm64;

        u64 cyclesCount{};
        CodeGenMode generate{};
    };
}
