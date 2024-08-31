#pragma once
#include <vector>
#include <variant>

#include <types.h>
namespace nuclear {
    using GprId = u64;
    struct RegisterInstrumentedUse {
        GprId id;
        GprId order;
        bool source;
    };
    enum LayoutPattern {
        Immediate
    };
    struct Memory {
        LayoutPattern pattern;
        std::variant<u16> value;
    };
    enum Instruction {
        Mov,
        Add,
        Ret
    };

    struct FetchResult {
        Instruction operation;
        std::vector<RegisterInstrumentedUse> params;
        Memory access;
    };
}
