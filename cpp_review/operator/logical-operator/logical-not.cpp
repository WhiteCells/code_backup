#include <iostream>

// !

void UseNot() {
    int a = 1;
    // a != a;
    a = !a;
    std::cout << a << '\n';
}

int main() {
    UseNot();
    return 0;
}