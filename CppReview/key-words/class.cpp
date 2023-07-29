#include <iostream>

class {}A;

void PrintEmptyClassSize() {
    std::cout << sizeof(A) << '\n';
}

int main() {
    PrintEmptyClassSize(); // 1
    return 0;
}