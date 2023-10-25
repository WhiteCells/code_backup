#include <iostream>

int main() {
    int a[10][2] {};
    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof a << std::endl;
    return 0;
}