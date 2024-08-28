#include <module.h>
int main() {
    nuclear::Module armGen{nuclear::Arm86};
    armGen.start();

    armGen.end();

    return {};
}