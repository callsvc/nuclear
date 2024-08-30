#include <jit_eastwood.h>
namespace nuclear {
    JitEastWood::JitEastWood(const CodeGenMode mode, std::vector<u8>& content) : generate(mode) {
        if (isArm(mode))
            arm64 = std::make_unique<ArmContext>(content);
    }

    u64 JitEastWood::execute() {
        u64 total{};
        while (cyclesCount) {
            u64 waste{};
            if (isArm(generate)) {
                waste = arm64->executeNext();
            }
            if (waste > cyclesCount)
                cyclesCount = 0;
            total += waste;
            cyclesCount -= waste;
        }
        return total;
    }
}
