#include "../../head-file.h"

/*
problme: 

url: 
 */

// time complexity: O()
// spatial complexity: O()
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (target == numbers[i] + numbers[j]) {
                return { i + 1, j + 1 };
            } else if (target < numbers[i] + numbers[j]) {
                --j;
            } else {
                ++i;
            }
        }
        return {};
    }
};

int main() {
    
    return 0;
}