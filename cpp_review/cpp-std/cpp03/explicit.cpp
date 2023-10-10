/*
    explicit 关键字用于修饰类的单参数构造函数，以限制其隐式转换
 */

class A {
private:
    int num_;
public:
    explicit A(int num) : num_(num) {}
    int GetNum() { return num_; }
};

class B {
public:
    int num_;
public:
    B(int num) : num_(num) {}
};

int main() {
    // A a = 20; // error，禁止隐式类型转换
    A a2(20); // ok，显式调用
    int ret1 = a2.GetNum(); // 显式调用
    int ret2 = A(10).GetNum(); // 显示调用

    B b = 20; // ok 没有 explicit 单参数构造函数就可以隐式转换

    return 0;
}