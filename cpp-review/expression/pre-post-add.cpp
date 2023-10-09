#include <iostream>
#include <chrono>

void PrePostAddTime() {
    auto start = std::chrono::high_resolution_clock::now();
    size_t k = 0;
    // for (size_t i = 0; i < (size_t)1e10; ++i) {
    for (size_t i = 0; i < 1e10; ++i) {
        // ++k;
        k++;
    }
    std::cout << k + 1 << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << duration.count() << "ms\n";
}

int main() {
    PrePostAddTime();
    return 0;
}