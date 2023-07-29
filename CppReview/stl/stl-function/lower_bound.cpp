#include <iostream>
#include <vector>


void UseLowerBound() {
    auto v = std::vector<int>{ 1, 2, 3, 6 }; // 找第一个比 3 大的值
    auto iter1 = lower_bound(v.begin(), v.end(), 3); // 返回的迭代器指向3
    auto iter2 = lower_bound(v.begin(), v.end(), 5); // 迭代器指向6（因为第一个大于等于6）

    std::cout << *iter2 << '\n'; //
}

int main() {
    UseLowerBound();
    return 0;
}