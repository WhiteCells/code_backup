#include <iostream>

int a[10];

const int n1 = 10;
int b[n1];

int n2 = 10;
// int c[n2]; // error


auto print(const int* const a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
};

void UseCArr() {

    int arr[1000] = { 100 };
    print(arr, 1000);

    std::cout << "-----------------" << '\n';

    int arr2[100];      // 垃圾数据
    print(arr2, 100);

    std::cout << '\n' << "-----------------" << '\n';

    int arr3[100]{ 0 }; // 全部置为 0
    print(arr3, 100);

    std::cout << '\n' << "-----------------" << '\n';

    int arr4[100] = {};
    print(arr4, 100);

}

int main() {
    UseCArr();
    return 0;
}