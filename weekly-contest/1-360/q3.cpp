#include "../../head-file.h"

/*
problme:

url:
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        priority_queue<int, vector<int>> heap;
        int sum = 0;
        for (auto& num : nums) {
            heap.push(num);
            sum += num;
        }
        if (sum == target) {
            return 0;
        }
        int cnt = 0;
        int cur = 0;
        while (!heap.empty()) {
            int top = heap.top();
            if (top < 2) {
                return -1;
            }
            sum -= (top >> 1);
            if (sum == target) {
                ++cnt;
                return cnt;
            }
            else if (sum < target) {
                return -1;
            }
            ++cnt;
            heap.pop();
            heap.push(top >> 1);
            heap.push(top >> 1);
        }
        return 0;
    }
};

int main() {
    // vector<int> nums { 1, 32, 1 };
    // int target = 35;
    // vector<int> nums { 1, 32, 1, 2 };
    // int target = 12;
    // vector<int> nums { 1, 2, 8 };
    // int target = 7;
    vector<int> nums { 16, 128, 32 };
    int target = 1;
    Solution s;
    cout << s.minOperations(nums, target) << '\n';
    return 0;
}