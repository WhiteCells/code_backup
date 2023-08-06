#include <iostream>

struct {}A;

void PrintEmptyStructSize() {
    std::cout << sizeof(A) << '\n';
}

struct B {
    int b;
    B(int b): b(b) {}
};

void StructB() {
    // B b; // 类 "B" 不存在默认构造函数
}

struct C {
    int c;
    C(int c = 0): c(c) {}
};

void StructC() {
    C c;
}

int main() {
    PrintEmptyStructSize(); // 1
    return 0;
}