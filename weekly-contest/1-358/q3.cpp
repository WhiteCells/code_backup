#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        map<int, int> mp;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        int pre_index = -1;
        int pre_val = 0;
        for (auto m : mp) {
            if (pre_index != -1) {
                if (abs(pre_index - m.second) >= x) {
                    res = min(res, abs(pre_val - m.first));
                }
            }
            else {
                pre_index = m.second;
                pre_val = m.first;
            }
        }
        return res;
    }
};

int main() {
    // nums = [5,3,2,10,15], x = 1
    // vector<int> nums = { 1, 2, 3, 4 };
    vector<int> nums = { 4, 3, 2, 4 };
    int x = 2;
    Solution s;
    cout << s.minAbsoluteDifference(nums, x);
}