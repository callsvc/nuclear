#pragma once

namespace nuclear {
    enum CodeGenMode {
        Arm86,
        MipsArm,
        Mips86
    };
    class Module {
    public:
        explicit Module(const CodeGenMode mode) : generate(mode) {}
        void start() const;
        void end() const;

    private:
        CodeGenMode generate;
    };
}