#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << x << ' ' << y << '\n';
    while (std::cin >> x) {
        ;
    }
    return 0;
}