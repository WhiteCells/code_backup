#include <iostream>

void ModifyConst() {
    const int a = 10;
    const int* p = &a;
    std::cout << a << '\n';
}


int main() {
    ModifyConst();
    return 0;
}