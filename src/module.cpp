#include <module.h>

#include <llvm/Support/TargetSelect.h>
namespace nuclear {
    void Module::start() const {
        if (generate == Arm86) {
            llvm::InitializeNativeTarget();
            llvm::InitializeNativeTargetAsmPrinter();
        }
    }

    void Module::end() const {
        if (generate) {

        }
    }
}
