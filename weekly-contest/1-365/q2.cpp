#include "../../head-file.h"

/*
problme:

url:
 */

class Solution {
public:
    long long maximumTripletValue(vector<int> &nums) {
        // [0, nums.size() - 3) 找最大值
        long long res = 0;
        int n = nums.size();
        long long one = 0, two = INT_MAX, three = 0;
        int ii = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > one) {
                ii = i;
                one = nums[i];
            }
        }
        int jj = 0;
        for (int j = ii + 1; j < n - 1; ++j) {
            if (nums[j] < two && one - nums[j] > 0) {
                jj = j;
                two = nums[j];
            }
        }
        for (int k = jj; k < n; ++k) {
            if (nums[k] > three) {
                three = nums[k];
            }
        }
        res = (one - two) * three;
        return res > 0 ? res : 0;
    }
};

class Solution2 {
public:
    long long maximumTripletValue(vector<int> &nums) {
        int center = 0, n = nums.size(), mn = INT_MAX;
        for (int i = 1; i + 1 < n; ++i) {
            if (nums[i] < mn) {
                center = i;
                mn = nums[i];
            }
        }
        sort(nums.begin(), nums.begin() + center);
        sort(nums.begin() + center + 1, nums.end());
        long long res = (long long)(nums[center - 1] - nums[center]) * nums[n - 1];
        return res > 0 ? res : 0;
    }
};

class Solution3 {
public:
    long long maximumTripletValue(vector<int> &nums) {
        int n = nums.size();
        // 枚举 j
        // 数组的前缀最大值 pre_max[]
        // [0, j - 1] 最大值 nums[i]
        // 数组的后缀最大值 suf_max[] 
        // [j + 1, n - 1] 最大值 nums[k] ，
        for (int j = 1; j + 1 < n; ++j) {

        }
    }
};

int main() {
    // 19 8 16
    // vector<int> nums{ 6, 11, 12, 12, 7, 9, 2, 11, 12, 4, 19, 14, 16, 8, 16 };
    vector<int> nums{ 8, 6, 3, 13, 2, 12, 19, 5, 19, 6, 10, 11, 9 };
    // cout << Solution().maximumTripletValue(nums) << '\n';
    cout << Solution2().maximumTripletValue(nums) << '\n';
    return 0;
}