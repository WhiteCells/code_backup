#include <iostream>


int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    std::cout << sizeof(arr) / sizeof(arr[0]) << '\n';
    return 0;
}