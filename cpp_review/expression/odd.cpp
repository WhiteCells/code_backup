#include <iostream>


// 判断是奇数
bool Odd(int n) {
    // n 为奇数时，二进制位最低位是 1

    // n 为偶数时，二进制位最低为是 0

    if (n & 1) {
        return true;
    }
    return false;
    // return n & 1 ? 1 : 0;
}

int main() {
    for (int i = 0; i < 100; ++i) {
        if (Odd(i)) {
            std::cout << i << ' ';
        }
    }
    return 0;
}