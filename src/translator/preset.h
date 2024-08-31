#pragma once
#include <string>
#include <unordered_map>
#include <types.h>
namespace nuclear::translator {
    struct PresetArmFmt {
        PresetArmFmt(const std::string& cc, const std::string& de) : conv(cc), dec(de) {
            validateConv();
        }
        std::string conv;
        std::string dec;

        static u64 getSizeof(const std::string& pattern);
        void validateConv();
    };
    inline std::unordered_map<u32, PresetArmFmt> runtime32lookup;

    class Preset {
    public:
        Preset();
        virtual ~Preset() = default;

        virtual void readNextInstruction() = 0;
        virtual u8 readMemory8(AddrInt address) = 0;
        virtual u16 readMemory16(AddrInt address) = 0;
        virtual u32 readMemory32(AddrInt address) = 0;

        virtual void reset() = 0;
    };
}
