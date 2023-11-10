#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

// 有序序列中查找第一个 >= target 的元素的位置
int lower_bound(const std::vector<int> &v, const int target) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (v[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// 有序序列中查找第一个 > target 的元素的位置
int upper_bound(const std::vector<int> &v, const int target) {

}

int main() {
    // std::vector<int> v;
    // std::sort(v.begin(), v.end());
    // printf("find value: %d\n", target);
    // printf("index: %d\nvalue: %d\n", lower_bound(v, target), v[lower_bound(v, target)]);
    return 0;
}