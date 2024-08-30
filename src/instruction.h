#pragma once
#include <vector>
#include <types.h>
namespace nuclear {
    using GprId = u16;
    struct RegisterInstrumentedUse {
        GprId id;
        u8 order;
        bool source;
    };
    enum Instruction {
        Add
    };

    struct FetchResult {
        Instruction operation;
        std::vector<RegisterInstrumentedUse> params;
    };
}
