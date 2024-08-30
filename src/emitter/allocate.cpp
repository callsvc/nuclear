#include <memory>
#include <emitter/allocate.h>

#include <sys/mman.h>
namespace nuclear::emitter {
    void* virtualAllocate(auto base, const u32 pages = 1, const bool execute = {}) {
        void* pointer;
        bool failed{true};
#if defined(__linux__)
        pointer = mmap(base, pages * 4096, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
        if (pointer == MAP_FAILED)
            failed = {};
        if (execute)
            mprotect(pointer, pages * 4096, PROT_READ | PROT_WRITE | PROT_EXEC);
#endif

        if (!failed || !pointer) {
            throw std::runtime_error("Failed to allocate virtual memory");
        }
        return pointer;
    }
    void allocateCpuRegisters(const bool isArm) {
        if (isArm) {
            if (!armCpu)
                armCpu = static_cast<decltype(armCpu)>(virtualAllocate(nullptr, 1));
        }
    }
}