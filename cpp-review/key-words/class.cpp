#include <iostream>

class {}A;
typedef class BB {
public:
    BB() {
        std::cout << "BB class" << '\n';
    }
}B;

void PrintEmptyClassSize() {
    std::cout << sizeof(A) << '\n';
    // A a; // error
    B b;
}

class C {
public:
    C(int val) {
        this->val = val;
        std::cout << "C()" << '\n';
    }
    C(const C& c) {
        this->val = c.val;
        std::cout << "C(const C&)" << '\n';
    }
    ~C() {
        std::cout << "~C()" << '\n';
    }
    int val;
};

void ClassC() {
    // C c(1);
    C c2(C(1));
}

int main() {
    // PrintEmptyClassSize(); // 1
    // ClassC();
    
    return 0;
}