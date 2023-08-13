#include <iostream>
#include <algorithm>

#include <vector>

auto print = [&](const auto& v) {
    for (const auto& ele : v) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
};

void InitVector() {
    std::vector<int> v1 { 1, 2, 3, };
    // std::vector<int> v = { 1, 2, 3 };
    print(v1);

    auto v2 = std::vector<int> { 1, 2, 3 };
    print(v2);

    std::vector<int> v3[2] { { 1, 2, 3 }, { 2, 3, 4 } };
    for (int i = 0; i < 2; ++i) {
        print(v3[i]);
    }

    std::vector<int> v4(3); // 预分配 3 个空间
    print(v4);
}

// 在使用std::vector<bool>时，需要注意它与其他类型的std::vector有所不同。
// std::vector<bool> 被特化为压缩存储，以节省内存空间
void VectorBool() {
    std::vector<bool> v { false, true, false, true };
    print(v); // 0 1 0 1

    // for (auto& ele : v) { // 非常量引用的初始值必须为左值C/C++(461)
    for (auto ele : v) {
        ele = true;  // 1 1 1 1
        // ele = false; // 0 0 0 0
    }
    print(v); // 1 1 1 1
}

void VectorPair() {
    using PII = std::pair<int, int>;

    std::vector<PII> v;

    std::pair<int, int> p1(1, 2);
    std::pair<int, int> p2(2, 0);
    std::pair<int, int> p3(3, -3);
    PII p4(4, 4);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(std::pair<int, int>(3, 4));
    v.push_back(std::make_pair<int, int>(5, 2));
    v.push_back(std::make_pair<int>(0, 2));

    std::sort(v.begin(), v.end(), std::greater<PII>()); // 降序

    for (const auto& val : v) {
        std::cout << val.first << ' ' << val.second << '\n';
    }
}

void fun(std::vector<int> v[], int n) {
    for (int i = 0; i < n; ++i) {
        for (auto& ele : v[i]) {
            std::cout << ele << ' ';
        }
        std::cout << '\n';
    }
}

void VectorArr() {
    std::vector<int> v[3] { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
    fun(v, 3);
}

void VectorVector() {
    std::vector<std::vector<int>> v {
        { 1, 2, 3 },
        { 2, 3, 4 },
        { 3, 4, 5 }, // 这里可以以 , 结尾
    };
    for (const auto& ele : v) {
        for (const auto& val : ele) {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }
}

void VectorEqualSign() {
    std::vector<int> v1 { 1, 2, 3 };
    std::vector<int> v2 { 2, 3, 4 };
    v2 = v1;
    print(v2);
}

int main() {
    // InitVector();
    // VectorBool();
    // VectorPair();
    // VectorArr();
    // VectorVector();
    VectorEqualSign();
    return 0;
}