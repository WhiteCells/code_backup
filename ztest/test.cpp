// #include <iostream>
// #include "stdio.h"
// 
// int main() {
//     class A {
//     public:
//         int a;
//         short b;
//         char c;
//         char *d;
//     };
//     // std::cout << sizeof(A) << std::endl;
// 
//     A aa;
//     aa.a = 1;
//     aa.b = 20;
//     aa.c = 'a';
//     aa.d = "test";
// 
//     // std::cout << &aa << std::endl;
//     // std::cout << &aa.a << std::endl;
//     // std::cout << &aa.b << std::endl;
//     // std::cout << &aa.c << std::endl;
//     // std::cout << &aa.d << std::endl;
// 
//     // printf("%p\n", &aa);   // 00000027379ff910
//     // printf("%p\n", &aa.a); // 00000027379ff910
//     // printf("%p\n", &aa.b); // 00000027379ff914
//     // printf("%p\n", &aa.c); // 00000027379ff916
//     // printf("%p\n", &aa.d); // 00000027379ff918
// 
//     // printf("test");
//     // while (1) {};
//     return 0;
// }


// #include <iostream>
// 
// using namespace std;
// 
// class A {
// public:
//     int v;
//     // int *ptr = new int(2);
//     void func() {
//         cout << __func__ << endl;
//     }
// };
// 
// int main() {
//     // A aa;
//     // cout << aa.v << endl;
//     // cout << *aa.ptr << endl;
// 
//     A *pa = nullptr;
//     // cout << *pa->ptr << endl;
//     // cout << pa->v << endl;
//     // pa->v = 2;
//     // 空对象可以调用成员方法，但不能调用成员属性
//     pa->func();
//     return 0;
// }

#include <iostream>
#include <Windows.h>
#include <format>

int main() {
    int a = 33;
    int mod = 16;
    std::cout << (a & (mod - 1)) << std::endl;
    std::string str = std::format("test{}", mod);
    return 0;
}