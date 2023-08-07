#include <iostream>
#include <chrono>

void PrePostAddTime() {
    auto start = std::chrono::high_resolution_clock::now();
    size_t k = 0;
    for (size_t i = 0; i < 1e10; ++i) {
        ++k;
        // k++;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // 1e9-2113ms-pre
    // 1e10-20093ms-pre
    // 1e9-2065ms-post
    // 1e10-19672ms-post
    std::cout << duration.count() << "ms\n";
}

int main() {
    PrePostAddTime();
    // PostAddTime();
    return 0;
}