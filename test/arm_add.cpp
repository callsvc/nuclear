#include <memory>
#include <vector>
#include <cstring>

#include <jit_eastwood.h>
using namespace nuclear;

int main() {
    const std::vector codes {
        0xd2800201, // MOV X1, #0x10
        0xd2800402, // MOV X2, #0x20
        0x8b020020, // ADD X0, X1, X2
        0xd65f03c0, // ERET
    };
    std::vector<u8> textRo{};
    textRo.resize(codes.size() * sizeof(u32));

    std::memcpy(&textRo[0], &codes[0], textRo.size());

    const auto nuke{std::make_unique<JitEastWood>(Arm86, textRo)};
    // Considering that each instruction takes 1 cycle
    nuke->addCycles(codes.size());
    nuke->execute();

    return {};
}
