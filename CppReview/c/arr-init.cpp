#include <iostream>

int a[10];

const int n1 = 10;
int b[n1];

int n2 = 10;
// int c[n2]; // error

void UseCArr() {

    // int arr[1000] = { 100 }; // 初始化下标为 0 的值为 100 其他值初始化为 0
    // for (int i = 0; i < 1000; ++i) {
    //     std::cout << arr[i] << ' ';
    // }
    // std::cout << '\n';

    int arr2[100];      // 垃圾数据
    int arr3[100]{ 0 }; // 全部置为 0

    for (int i = 0; i < 100; ++i) {
        std::cout << arr2[i] << ' ';
    }
    std::cout << '\n' << "-----------------" << '\n';

    for (int i = 0; i < 100; ++i) {
        std::cout << arr3[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    UseCArr();
    return 0;
}