#include <iostream>

void Swap(int& x, int& y) {
    int a = x, b = y;
    std::swap(a, b);
}

int main(int argc, char const *argv[]) {
    int x = 10;
    int y = 20;
    Swap(x, y);
    std::cout << x << ' ' << y << '\n';
    return 0;
}
