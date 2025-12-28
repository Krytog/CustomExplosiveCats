#include <iostream>

#include <Server/Mock/MockGameIO.h>
#include <Game/Runtime/Runtime.h>

int main() {
    std::cout << "Running MOCK EC server..." << std::endl;

    MockGameIO io;
    const size_t seed = 31337;
    Runtime runtime(seed, &io);
    runtime.RunGameLoop();

    std::cout << "MOCK EC server has exited!" << std::endl;
    return 0;
}
