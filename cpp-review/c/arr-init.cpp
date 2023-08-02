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

int globalArray[5]; // 全局变量数组，默认初始化为 0

void foo() {
    static int staticArray[10]; // 静态局部变量数组，默认初始化为 0
    int localStaticArray[15]; // 自动局部变量数组，默认初始化为不确定的值
}

class MyClass {
    static int staticArray[10]; // 静态成员变量数组，默认初始化为 0
};

int explicitArray[5] = { 0 }; // 显式初始化数组的所有元素为 0


bool FlagArr[100]; // 全局变量数组，默认初始化为 0


void FlagArrTest() {
    for (int i = 0; i < 100; ++i) {
        std::cout << FlagArr[i] << ' ';
    }
}
const int gArray[1000]{ 1 };

void constgArray() {
    for (int i = 0; i < 1000; ++i) {
        std::cout << gArray[i] << ' ';
    }
}

int main() {
    // UseCArr();
    // FlagArrTest();
    constgArray();
    return 0;
}