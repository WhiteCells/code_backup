// #include <iostream>
// 
// unsigned int clz_manual(unsigned int value) {
//     if (value == 0) return 32;
// 
//     unsigned int n = 0;
//     if ((value & 0xFFFF0000) == 0) { n += 16; value <<= 16; }
//     if ((value & 0xFF000000) == 0) { n += 8; value <<= 8; }
//     if ((value & 0xF0000000) == 0) { n += 4; value <<= 4; }
//     if ((value & 0xC0000000) == 0) { n += 2; value <<= 2; }
//     if ((value & 0x80000000) == 0) { n += 1; }
// 
//     return n;
// }
// 
// int main() {
//     std::cout << 32 - clz_manual(16) << std::endl;
//     std::cout << 32 - __builtin_clz(16) << std::endl;
//     return 0;
// }

#include <sys/time.h>

int main() {

}