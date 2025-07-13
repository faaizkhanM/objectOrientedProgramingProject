#include "loading.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <iomanip>

void loadinganimation::simulateLoadingProcess() {
    // Simulate a loading process
    std::cout << "Loading, please wait... ";
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << ".";
        if (i % 20 == 0) {
            std::cout << std::endl << "Progress: " << i << "% ";
        }
    }
    std::cout << std::endl;
}