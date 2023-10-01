#include "../../head-file.h"

/*
problme:
输入：nums = [1,10,3,4,19]
输出：133
解释：下标三元组 (1, 2, 4) 的值是 (nums[1] - nums[2]) * nums[4] = 133 。
可以证明不存在值大于 133 的有序下标三元组。
url:
 */

class Solution {
public:
    long long maximumTripletValue(vector<int> &nums) {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int one = nums[i];
            for (int j = i + 1; j < n; ++j) {
                int two = nums[j];
                for (int k = j + 1; k < n; ++k) {
                    int three = nums[k];
                    res = max(res, (long long)(one - two) * three);
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}