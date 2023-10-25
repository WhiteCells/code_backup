#include "../../head-file.h"

/*
problme:

url:
 */

// time complexity: O()
// spatial complexity: O()
class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (0 < nums[0]) { // nums 内全为正数, 则三数之和不会为 0
            return {};
        }
        for (int i = 0; i + 2 < nums.size(); ++i) { // nums.size() 最小为 3
            if (0 != i && nums[i] == nums[i - 1]) { // 当 nums[i] 重复出现时需要去重
                continue;
            }
            int j = i + 1, k = nums.size() - 1; // 左右指针
            while (j < k) {
                if (j != i + 1 && nums[j] == nums[j - 1]) { // 当 nums[j] 重复出现时需要去重
                    ++j;
                    continue;
                }
                if (0 == nums[i] + nums[j] + nums[k]) {
                    res.push_back({ nums[i], nums[j], nums[k] });
                    ++j;
                    --k;
                } else if (0 < nums[i] + nums[j] + nums[k]) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return res;
    }
};

// time complexity: O()
// spatial complexity: O()
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (0 < nums[0]) { // nums 内全为正数, 则三数之和不会为 0
            return {};
        }
        for (int i = 0; i + 2 < n; ++i) { // nums.size() 最小为 3
            if (0 < i && nums[i] == nums[i - 1]) { // 当 nums[i] 重复出现时需要去重
                continue;
            }
            int j = i + 1, k = n - 1; // 左右指针
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (0 == sum) {
                    res.push_back({ nums[i], nums[j], nums[k] });
                    ++j;
                    while (j > i + 1 && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    --k;
                    while (k > j && nums[k] == nums[k + 1]) {
                        --k;
                    }
                } else if (0 < sum) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums { -1, 0, 1, 2, -1, -4 };
    auto res = Solution1().threeSum(nums);

    for (const auto &ele : res) {
        for (const auto &v : ele) {
            cout << v << ' ';
        }
        cout << '\n';
    }
    return 0;
}