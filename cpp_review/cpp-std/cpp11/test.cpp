#include <iostream>
#include <vector>

// 定义一个简单的类，含有动态分配的资源
class MyResource {
private:
    int* data_;
public:
    MyResource() {
        std::cout << "Constructing MyResource" << std::endl;
        // 分配资源，比如分配内存、连接数据库等操作
        data_ = new int[1000000];
    }

    ~MyResource() {
        std::cout << "Destructing MyResource" << std::endl;
        // 释放资源，比如释放内存、关闭数据库连接等操作
        delete[] data_;
    }

    // 移动构造函数
    MyResource(MyResource&& other) noexcept {
        std::cout << "Moving MyResource" << std::endl;
        // 直接接管资源
        data_ = other.data_;
        other.data_ = nullptr;
    }

    // 移动赋值运算符
    MyResource& operator=(MyResource&& other) noexcept {
        std::cout << "Moving assignment of MyResource" << std::endl;
        if (this != &other) {
            // 释放当前对象的资源
            delete[] data_;
            // 接管资源
            data_ = other.data_;
            other.data_ = nullptr;
        }
        return *this;
    }
};

int main() {
    // 创建一个存储 MyResource 对象的容器
    std::vector<MyResource> resources;

    // 添加一些 MyResource 对象到容器中
    for (int i = 0; i < 3; ++i) {
        resources.push_back(MyResource());
    }

    // 移动语义演示：将容器中的对象移动到另一个容器
    std::vector<MyResource> newResources(std::make_move_iterator(resources.begin()),
                                         std::make_move_iterator(resources.end()));

    return 0;
}