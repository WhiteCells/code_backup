#include <iostream>
#include "stdio.h"

int main() {
    class A {
    public:
        int a;
        short b;
        char c;
        char *d;
    };
    std::cout << sizeof(A) << std::endl;
    // std::cout << sizeof(short) << std::endl;

    A aa;
    aa.a = 1;
    aa.b = 20;
    aa.c = 'a';
    aa.d = "test";

    // std::cout << &aa << std::endl;
    // std::cout << &aa.a << std::endl;
    // std::cout << &aa.b << std::endl;
    // std::cout << &aa.c << std::endl;
    // std::cout << &aa.d << std::endl;

    printf("%p\n", &aa);   // 00000027379ff910
    printf("%p\n", &aa.a); // 00000027379ff910
    printf("%p\n", &aa.b); // 00000027379ff914
    printf("%p\n", &aa.c); // 00000027379ff916
    printf("%p\n", &aa.d); // 00000027379ff918
    return 0;
}