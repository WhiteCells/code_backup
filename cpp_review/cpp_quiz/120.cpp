#include <iostream>

int main() {
    int a = 10;
    int b = 20;
    int x, y;
    x = a, b; // , 优先级低
    y = (a, b);
    std::cout << x << ' ' << y; // 10 20
}