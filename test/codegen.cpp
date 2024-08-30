#include <memory>
#include <vector>
#include <cstring>

#include <jit_eastwood.h>
using namespace nuclear;

int main() {
    const std::vector codes {
        0x8b020020
    };

    std::vector<u8> textRo{};
    textRo.resize(codes.size() * sizeof(u32));

    std::memcpy(&textRo[0], &codes[0], textRo.size());

    const auto nuke{std::make_unique<JitEastWood>(Arm86, textRo)};

    nuke->addCycles(1);
    nuke->execute();

    return {};
}
