#include <iostream>
#include <ctime>


double InLoopAssignment() {
    double s = std::clock();
    int a = 10;
    for (int i = 0; i < 1e9; ++i) {
        a = 100;
    }
    double e = std::clock();
    return e - s;
}

double OutLoopAssignment() {
    double s = std::clock();
    for (int i = 0; i < 1e9; ++i) {
        int a = 10;
        a = 100;
    }
    double e = std::clock();
    return e - s;
}


int main() {
    std::cout << InLoopAssignment()  << '\n'; // 1997ms
    std::cout << OutLoopAssignment() << '\n'; // 1985ms
    return 0;
}