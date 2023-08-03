#include <iostream>

// template <typename T>
template <class T>
class Add {
private:
    T a;
    T b;
public:
    Add(T a, T b) : a(a), b(b) {
        std::cout << a + b << '\n';
    }
};

int main() {
    Add<int>(1, 3);
    Add<double>(1.1, 3.3);
}