#include <iostream>
#include <algorithm>
#include <functional>

#include <vector>

auto print = [&](const auto& v) {
    for (const auto& ele : v) {
        std::cout << ele << ' ';
    }
    std::cout << '\n';
};


void UseVectorBool() {

    std::vector<bool> v{ false, true, false, true }; // ???

    // for (auto& ele : v) { // 非常量引用的初始值必须为左值C/C++(461)
    for (auto ele : v) {
        ele = true;  // 1 1 1 1
        // ele = false; // 0 0 0 0
    }
    for (const auto val : v) {
        std::cout << val << " ";
    }
    std::cout << '\n';

    // std::vector<int> v{ 0, 0, 0, 0 };
    // for (auto ele : v) {
    //     ele = 1;
    // }
    // for (auto ele : v) {
    //     std::cout << ele << ' ';
    // }
    // std::cout << '\n';
}

void UseVectorPair() {
    using PII = std::pair<int, int>;

    std::vector<PII> v;

    std::pair<int, int> p1(1, 2);
    std::pair<int, int> p2(2, 0);
    std::pair<int, int> p3(3, -3);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    std::sort(v.begin(), v.end(), std::greater<PII>()); // 默认按照第一个数进行排序

    for (const auto& val : v) {
        std::cout << val.first << ' ' << val.second << '\n';
    }

}

void InitVector() {
    std::vector<int> v{ 1, 2, 3 };
    std::cout << sizeof(v) << '\n';
    auto it_begin = v.begin();
    auto it_rbegin = v.rbegin();
    std::cout << *it_begin << ' ' << *it_rbegin << '\n';

    auto v2 = std::vector<int>{ 1, 2, 3, 4 };
    print(v2);

    std::vector<int> v3[2]{ { 1, 2, 3 }, { 2, 3, 4 } };
    std::cout << sizeof(v3) << '\n';
    for (int i = 0; i < 2; ++i) {
        print(v3[i]);
    }

    std::vector<int> v4(4);
    std::cout << sizeof(v4) << '\n';
    print(v4);
}

int main() {
    UseVectorBool();
    UseVectorPair();
    InitVector();
    return 0;
}