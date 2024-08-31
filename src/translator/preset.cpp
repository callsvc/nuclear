#include <boost/algorithm/string.hpp>
#include <translator/preset.h>

namespace nuclear::translator {
    struct PatternsSize {
        std::string pattern;
        u64 size;
    };

    u64 PresetArmFmt::getSizeof(const std::string& pattern) {
        static std::vector<PatternsSize> acceptable;
        [[unlikely]] if (acceptable.empty()) {
            acceptable.emplace_back("sf", 1);
            acceptable.emplace_back("op", 1);
            acceptable.emplace_back("opc", 2);
            acceptable.emplace_back("?", 1);
            acceptable.emplace_back("s", 1);
            acceptable.emplace_back("0", 1);
            acceptable.emplace_back("1", 1);
            acceptable.emplace_back("rm", 5);
            acceptable.emplace_back("rn", 5);
            acceptable.emplace_back("rd", 5);
            acceptable.emplace_back("imm16", 16);
        }
        for (const auto& defined : acceptable) {
            if (defined.pattern == pattern) {
                return defined.size;
            }
        }

        for (const auto& none : {"bits", "hex"}) {
            if (pattern.find(none) == std::string::npos)
                continue;
            auto str{pattern};
            str.erase(0, str.find('(') + 1);
            str.erase(str.find(')'), str.size());
            return str.size() * (none == "bits" ? 1 : 4);
        }
        if (pattern.find("**") != std::string::npos) {
            return pattern.size();
        }
        return {};
    }

    void PresetArmFmt::validateConv() {
        std::vector<std::string> result;
        split(result, conv, boost::is_any_of("-"));
        u32 acc{};

        for (const auto& pattern : result) {
            acc += getSizeof(pattern);
        }
        if (acc == 32)
            return;

        throw std::runtime_error("Invalid arm format");
    }

    void initArmLookup() {
        runtime32lookup.emplace(0xd2800000, PresetArmFmt("sf-opc-bits(100101)-**-imm16-rd", "MOV RD, (imm)"));
        runtime32lookup.emplace(0x8b000000, PresetArmFmt("sf-op-s-bits(01011)-**-0-rm-******-rn-rd", "ADD (regs)"));
        runtime32lookup.emplace(0xd69f03e0, PresetArmFmt("hex(d69f03e0)", "ERET"));
    }

    Preset::Preset() {
        if (runtime32lookup.empty()) {
            initArmLookup();
        }
    }
}
