#include <iostream>

struct {}A;

void PrintEmptyStructSize() {
    std::cout << sizeof(A) << '\n';
}

int main() {
    PrintEmptyStructSize(); // 1
    return 0;
}