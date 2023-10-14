#include "D:/distake/Coding/head-file.h"

/*
 * @Author: WhiteCells
 * @Date: 2023-05-23 17:55:57
 * @Last Modified by: WhiteCells
 * @Last Modified time: 2023-05-23 17:55:57
 * @Description: 860.柠檬水找零
 * https://leetcode.cn/problems/lemonade-change/
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(2, 0); // 已有零钱 5 和 10 的张数
        for (int i = 0; i < bills.size(); ++i) {
            if (5 == bills[i]) {
                change[0]++; // 零钱 5 增加
            }
            else if (10 == bills[i]) {
                if (change[0] <= 0) { // 没有零钱 5 无法找零
                    return false;
                }
                change[1]++; // 零钱 10 增加
                change[0]--; // 零钱 5 找零
            }
            else if (20 == bills[i]) {
                if (change[0] > 0 && change[1] > 0) { // 优先找零 10 和 5
                    change[0]--;
                    change[1]--;
                }
                else if (change[1] < 0 && change[0] >= 3){ // 找 3 * 5
                    change[0] -= 3;
                }
                else { // 无法找零
                    return false;
                }
            }
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<int> bills2 {5,5,5,10,5,5,10,20,20,20};
    vector<int> bills {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 20, 5, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 5, 10, 5, 5, 10, 5, 20, 5, 5, 20, 5, 10, 5, 5, 20, 5, 5, 5, 5, 5, 5, 10, 20, 5, 20, 20, 10, 5, 20, 20, 5, 10, 5, 5, 5, 5, 5, 5, 20, 20, 20, 20, 5, 5, 10, 5, 20, 5, 5, 5, 5, 10, 10, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 20, 10, 10, 20, 5, 5, 5, 5, 20, 20, 5, 5, 5, 5, 20, 5, 20, 20, 5, 5, 10, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 10, 20, 20, 5, 5, 10, 20, 5, 5, 5, 5, 10, 20, 5, 5, 10, 20, 5, 10, 10, 5, 5, 5, 5, 5, 5, 10, 10, 10, 5, 10, 5, 10, 5, 5, 10, 10, 5, 5, 5, 20, 5, 20, 10, 20, 5, 5, 5, 20, 10, 5, 5, 20, 5, 5, 5, 10, 5, 5, 10, 5, 5, 20, 5, 10, 10, 5, 5, 10, 5, 5, 10, 5, 10, 5, 20, 10, 5, 10, 10, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 5, 5, 10, 5, 10, 10, 5, 20, 20, 5, 10, 10, 10, 5, 10, 5, 10, 5, 10, 5, 5, 10, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 20, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 5, 5, 10, 20, 5, 5, 5, 20, 20, 5, 10, 5, 5, 5, 10, 5, 10, 20, 20, 5, 5, 5, 5, 5, 5, 20, 10, 5, 10, 5, 5, 20, 10, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 10, 5, 10, 20, 10, 10, 5, 5, 20, 10, 20, 5, 5, 5, 10, 5, 5, 5, 10, 5, 20, 20, 20, 10, 20, 5, 5, 5, 5, 20, 5, 20, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 10, 5, 5, 5, 20, 5, 5, 5, 10, 10, 5, 5, 5, 5, 5, 20, 20, 20, 5, 5, 5, 5, 20, 5, 20, 5, 20, 20, 10, 10, 5, 5, 5, 20, 10, 20, 10, 20, 5, 20, 5, 5, 5, 10, 10, 5, 5, 5, 5, 10, 10, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 10, 20, 20, 5, 20, 10, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 10, 5, 10, 10, 20, 5, 20, 5, 20, 10, 5, 5, 5, 20, 5, 10, 10, 5, 5, 10, 5, 10, 5, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 10, 5, 10, 20, 20, 5, 5, 20, 5, 10, 5, 20, 5, 20, 20, 5, 5, 5, 20, 20, 20, 5, 5, 5, 5, 20, 10, 5, 5, 10, 10, 10, 5, 10, 5, 10, 5, 20, 5, 5, 5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 20, 20, 10, 10, 5, 5, 20, 5, 5, 5, 5, 20, 20, 20, 20, 5, 5, 20, 20, 5, 20, 5, 5, 5, 10, 20, 10, 5, 20, 5, 5, 5, 5, 10, 10, 5, 10, 5, 5, 10, 5, 5, 20, 10, 20, 5, 5, 5, 10, 5, 5, 10, 10, 5, 20, 5, 5, 20, 5, 5, 20, 10, 10, 5, 5, 10, 5, 5, 20, 5, 10, 5, 20, 20, 10, 10, 20, 5, 5, 5, 20, 5, 5, 20, 20, 10, 20, 10, 10, 5, 20, 10, 5, 10, 5, 10, 5, 5, 20, 5, 20, 20, 5, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 20, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 10, 5, 10, 5, 20, 20, 20, 20, 5, 5, 20, 5, 5, 5, 20, 5, 20, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 20, 5, 20, 20, 5, 5, 5, 5, 10, 5, 20, 20, 5, 20, 5, 10, 5, 5, 5, 5, 20, 5, 5, 5, 20, 20, 5, 5, 5, 20, 10, 20, 5, 5, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 20, 10, 20, 20, 5, 5, 10, 10, 5, 10, 10, 5, 5, 10, 10, 5, 5, 5, 5, 5, 10, 5, 20, 5, 10, 5, 20, 10, 5, 10, 5, 10, 20, 10, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 10, 10, 20, 20, 20, 5, 20, 20, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 20, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 20, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 20, 5, 5, 5, 20, 5, 20, 5, 20, 10, 5, 5, 5, 5, 10, 5, 10, 5, 20, 20, 10, 5, 5, 20, 10, 10, 5, 10, 20, 5, 5, 5, 10, 5, 20, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 10, 10, 5, 5, 10, 5, 10, 10, 20, 10, 20, 5, 5, 5, 10, 10, 5, 5, 20, 5, 20, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 20, 5, 5, 10, 10, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 20, 5, 10, 5, 5, 10, 5, 10, 10, 5, 10, 10, 5, 20, 20, 5, 5, 20, 5, 5, 5, 5, 5, 20, 10, 10, 5, 10, 5, 20, 20, 5, 5, 5, 5, 5, 10, 5, 20, 10, 20, 5, 20, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 10, 5, 5, 20, 20, 5, 20, 20, 5, 5, 5, 10, 20, 5, 5, 10, 10, 5, 5, 20, 10, 20, 5, 10, 5, 5, 5, 5, 20, 5, 5, 5, 5, 20, 20, 5, 20, 5, 10, 10, 5, 10, 20, 20, 20, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 20, 10, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 10, 5, 10, 20, 10, 20, 5, 5, 5, 5, 10, 5, 20, 5, 20, 5, 20, 5, 10, 5, 10, 10, 10, 5, 5, 5, 20, 20, 5, 5, 10, 10, 10, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 20, 10, 10, 20, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 20, 5, 10, 5, 20, 5, 10, 5, 5, 20, 5, 5, 5, 10, 5, 5, 5, 10, 5, 5, 20, 20, 5, 5, 10, 20, 10, 20, 5, 10, 20, 5, 5, 10, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 10, 10, 10, 5, 20, 20, 5, 5, 20, 20, 10, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 20, 10, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 10, 20, 20, 5, 5, 5, 5, 20, 5, 5, 5, 5, 10, 20, 5, 5, 10, 5, 5, 10, 5, 10, 20, 20, 5, 10, 5, 10, 5, 5, 10, 10, 5, 5, 5, 5, 5, 5, 20, 5, 20, 20, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 20, 10, 10, 5, 5, 10, 5, 20, 5, 5, 10, 10, 20, 5, 5, 5, 20, 10, 5, 5, 5, 10, 5, 5, 5, 5, 5, 20, 5, 10, 5, 5, 10, 20, 5, 5, 20, 10, 5, 5, 20, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 10, 10, 5, 5, 5, 5, 10, 5, 20, 5, 10, 10, 5, 10, 5, 5, 5, 5, 5, 5, 10, 20, 5, 5, 20, 20, 5, 20, 10, 5, 5, 5, 10, 5, 20, 5, 5, 10, 20, 5, 5, 20, 10, 20, 10, 5, 5, 5, 10, 5, 5, 5, 5, 5, 10, 20, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 10, 5, 20, 10, 5, 20, 10, 20, 10, 5, 20, 5, 5, 5, 5, 5, 20, 20, 10, 10, 10, 10, 5, 5, 20, 5, 10, 5, 5, 10, 20, 5, 5, 5, 5, 20, 5, 5, 5, 10, 5, 5, 10, 5, 20, 20, 10, 10, 5, 5, 10, 5, 5, 10, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 10, 5, 5, 20, 10, 10, 5, 20, 20, 20, 5, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 5, 10, 20, 5, 20, 5, 20, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 20, 10, 5, 10, 10, 5, 20, 10, 5, 20, 20, 5, 5, 20, 5, 5, 10, 5, 5, 10, 5, 5, 10, 10, 5, 5, 20, 10, 5, 20, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 10, 5, 10, 20, 10, 10, 5, 5, 10, 5, 20, 10, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 10, 20, 20, 5, 5, 5, 20, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 20, 10, 5, 5, 5, 5, 10, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 5, 5, 10, 20, 20, 20, 5, 20, 5, 10, 5, 10, 20, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 20, 10, 5, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 10, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 5, 10, 5, 10, 5, 10, 20, 5, 5, 5, 5, 20, 10, 5, 5, 5, 20, 5, 10, 10, 5, 5, 10, 20, 5, 10, 5, 5, 5, 20, 10, 5, 20, 5, 5, 5, 20, 20, 10, 20, 10, 5, 20, 5, 10, 10, 20, 10, 5, 5, 10, 5, 20, 20, 5, 5, 5, 5, 10, 5, 10, 20, 20, 20, 10, 20, 5, 10, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 20, 10, 20, 5, 20, 5, 5, 5, 20, 10, 5, 5, 20, 5, 10, 5, 5, 5, 10, 5, 5, 10, 10, 5, 20, 20, 20, 5, 5, 5, 5, 20, 5, 20, 20, 5, 10, 5, 20, 5, 10, 20, 5, 5, 10, 5, 5, 5, 5, 5, 10, 10, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 5, 20, 5, 10, 10, 5, 5, 10, 20, 10, 5, 5, 5, 5, 10, 5, 5, 10, 5, 10, 5, 10, 5, 20, 5, 5, 10, 5, 20, 5, 5, 10, 5, 20, 5, 20, 20, 10, 5, 20, 10, 20, 20, 5, 20, 5, 20, 5, 5, 20, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 20, 10, 5, 5, 20, 20, 20, 10, 20, 20, 20, 10, 10, 20, 5, 10, 5, 5, 10, 5, 5, 5, 20, 10, 20, 20, 20, 5, 5, 5, 10, 5, 5, 5, 20, 10, 5, 10, 5, 5, 10, 5, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 10, 20, 10, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 10, 20, 5, 10, 20, 10, 10, 5, 5, 20, 5, 20, 5, 5, 20, 5, 20, 20, 5, 5, 5, 10, 20, 5, 5, 10, 5, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 20, 10, 5, 5, 10, 5, 5, 10, 10, 10, 5, 5, 10, 5, 10, 5, 20, 10, 20, 10, 20, 20, 10, 5, 10, 10, 10, 5, 20, 5, 5, 5, 5, 10, 5, 5, 20, 20, 10, 10, 10, 5, 10, 5, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 10, 20, 5, 5, 5, 20, 10, 10, 10, 20, 20, 10, 5, 5, 10, 20, 20, 10, 5, 5, 5, 10, 10, 5, 20, 5, 10, 20, 20, 5, 5, 20, 10, 5, 20, 5, 5, 10, 5, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 20, 5, 5, 20, 5, 5, 5, 20, 20, 5, 20, 20, 5, 5, 10, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 20, 20, 5, 10, 5, 5, 5, 5, 5, 10, 5, 20, 10, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 10, 5, 5, 20, 5, 5, 20, 20, 20, 20, 5, 10, 5, 20, 5, 5, 20, 5, 5, 5, 10, 5, 10, 5, 20, 5, 5, 5, 5, 20, 5, 5, 20, 20, 5, 5, 20, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 20, 20, 5, 5, 5, 5, 5, 10, 10, 5, 10, 10, 10, 5, 5, 5, 20, 5, 20, 10, 20, 20, 5, 5, 10, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 10, 10, 5, 10, 10, 5, 10, 5, 20, 10, 10, 5, 5, 20, 5, 5, 10, 10, 10, 5, 10, 10, 10, 5, 10, 5, 5, 10, 5, 10, 20, 20, 5, 20, 5, 5, 5, 10, 10, 20, 5, 5, 5, 10, 5, 5, 5, 5, 5, 20, 5, 5, 10, 20, 5, 20, 5, 5, 10, 20, 10, 20, 5, 10, 5, 5, 5, 10, 20, 10, 5, 10, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 5, 20, 10, 10, 5, 20, 5, 20, 5, 5, 10, 5, 5, 20, 5, 20, 20, 10, 20, 10, 5, 20, 5, 20, 20, 20, 5, 5, 5, 10, 5, 20, 20, 10, 5, 20, 5, 5, 5, 20, 10, 5, 5, 20, 20, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 5, 5, 20, 5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 10, 10, 20, 5, 20, 5, 5, 5, 20, 10, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 20, 20, 10, 5, 5, 5, 10, 5, 20, 5, 10, 5, 20, 5, 10, 5, 5, 5, 5, 5, 20, 20, 5, 5, 5, 5, 5, 20, 10, 20, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 10, 5, 10, 5, 5, 10, 5, 5, 10, 10, 20, 5, 20, 5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 5, 5, 20, 10, 5, 5, 10, 5, 10, 5, 20, 5, 10, 5, 5, 20, 5, 10, 5, 5, 5, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 10, 5, 20, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 20, 20, 5, 5, 10, 5, 5, 5, 5, 10, 10, 10, 5, 5, 20, 5, 10, 20, 5, 5, 5, 5, 5, 10, 10, 5, 20, 5, 10, 5, 5, 5, 5, 20, 5, 20, 10, 20, 10, 10, 20, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 5, 10, 5, 5, 5, 20, 20, 20, 5, 10, 20, 20, 10, 20, 20, 20, 5, 10, 20, 5, 10, 5, 10, 5, 20, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 20, 10, 5, 5, 20, 5, 5, 5, 20, 5, 10, 20, 10, 20, 5, 20, 5, 5, 5, 5, 20, 5, 5, 5, 5, 20, 5, 5, 5, 5, 20, 5, 5, 20, 5, 20, 10, 5, 5, 5, 20, 10, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 10, 10, 5, 5, 10, 20, 20, 20, 20, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 5, 20, 5, 20, 5, 10, 20, 5, 10, 20, 5, 20, 5, 10, 20, 5, 20, 5, 20, 20, 5, 10, 5, 20, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 20, 5, 5, 5, 5, 5, 5, 5, 10, 20, 10, 10, 10, 20, 5, 5, 10, 20, 5, 20, 20, 10, 5, 5, 20, 5, 20, 5, 20, 10, 5, 10, 5, 5, 5, 5, 5, 10, 5, 5, 10, 5, 5, 20, 5, 20, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 20, 5, 20, 5, 10, 10, 5, 5, 10, 5, 20, 20, 5, 5, 5, 10, 20, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 10, 10, 5, 5, 20, 5, 10, 5, 20, 10, 10, 5, 10, 20, 5, 5, 10, 5, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 10, 5, 10, 20, 20, 5, 10, 5, 20, 5, 10, 5, 5, 20, 5, 5, 20, 5, 5, 20, 5, 5, 10, 20, 5, 5, 5, 20, 20, 20, 5, 20, 10, 5, 5, 5, 5, 5, 5, 10, 5, 20, 5, 10, 5, 20, 5, 20, 5, 20, 5, 10, 5, 20, 20, 10, 5, 5, 10, 20, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 10, 10, 10, 10, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 20, 20, 5, 5, 5, 5, 5, 5, 10, 5, 20, 20, 10, 20, 5, 5, 5, 5, 10, 20, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 20, 20, 5, 5, 5, 10, 5, 5, 10, 10, 10, 20, 10, 5, 20, 5, 5, 10, 20, 5, 5, 10, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 20, 5, 5, 20, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 20, 10, 5, 20, 20, 5, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 10, 10, 20, 10, 5, 5, 10, 5, 5, 10, 10, 5, 5, 5, 5, 5, 20, 10, 5, 5, 20, 5, 5, 20, 5, 10, 10, 20, 20, 20, 10, 20, 5, 20, 20, 5, 5, 20, 5, 20, 5, 5, 20, 5, 20, 5, 5, 10, 5, 20, 10, 5, 5, 5, 5, 10, 5, 20, 5, 20, 20, 20, 5, 10, 5, 5, 5, 5, 10, 20, 10, 10, 20, 5, 10, 5, 5, 10, 5, 20, 5, 20, 10, 20, 5, 5, 5, 5, 20, 20, 5, 5, 5, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 20, 5, 10, 20, 5, 20, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 20, 5, 5, 5, 5, 5, 5, 10, 5, 10, 5, 10, 5, 5, 5, 10, 10, 20, 5, 5, 10, 20, 5, 20, 5, 20, 10, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 5, 20, 20, 10, 5, 5, 10, 5, 5, 5, 10, 5, 10, 10, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 5, 10, 5, 10, 10, 10, 10, 5, 5, 5, 5, 5, 20, 10, 5, 5, 5, 10, 5, 5, 20, 5, 5, 10, 5, 5, 10, 10, 10, 5, 10, 20, 5, 5, 20, 5, 20, 5, 5, 20, 5, 5, 20, 20, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 10, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 10, 5, 5, 10, 20, 20, 5, 5, 20, 5, 5, 20, 5, 10, 20, 20, 5, 5, 5, 5, 5, 5, 20, 20, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 20, 20, 20, 5, 5, 5, 10, 10, 5, 5, 10, 5, 5, 5, 10, 10, 5, 5, 10, 10, 10, 20, 5, 20, 5, 5, 5, 5, 5, 5, 5, 10, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 10, 5, 10, 5, 5, 5, 5, 10, 10, 20, 10, 20, 5, 10, 20, 20, 20, 5, 5, 10, 5, 20, 20, 5, 20, 20, 5, 10, 5, 5, 10, 20, 5, 5, 5, 5, 5, 10, 5, 10, 5, 10, 20, 5, 5, 5, 5, 5, 20, 10, 20, 10, 20, 20, 5, 5, 20, 20, 5, 5, 10, 5, 5, 5, 20, 10, 10, 5, 5, 20, 5, 5, 5, 20, 10, 10, 5, 5, 5, 10, 5, 10, 10, 20, 5, 10, 5, 20, 5, 5, 5, 20, 10, 20, 5, 10, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 20, 5, 20, 5, 5, 20, 5, 10, 5, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 20, 5, 10, 5, 5, 5, 10, 10, 5, 5, 5, 20, 5, 5, 20, 20, 5, 5, 10, 20, 5, 5, 5, 5, 5, 10, 20, 5, 5, 10, 20, 10, 20, 5, 10, 5, 5, 20, 20, 5, 5, 5, 10, 5, 5, 10, 5, 5, 5, 20, 20, 10, 5, 5, 20, 20, 5, 20, 5, 10, 20, 5, 5, 5, 10, 5, 5, 5, 10, 5, 5, 20, 10, 5, 20, 20, 20, 5, 5, 10, 5, 20, 20, 20, 20, 10, 5, 10, 10, 10, 5, 5, 5, 20, 5, 10, 10, 20, 5, 5, 5, 5, 5, 20, 5, 5, 20, 10, 5, 5, 20, 10, 5, 10, 10, 20, 10, 20, 5, 5, 5, 10, 10, 5, 5, 10, 20, 20, 5, 5, 5, 10, 5, 5, 20, 5, 5, 5, 5, 5, 10, 20, 10, 5, 10, 5, 5, 5, 5, 5, 5, 10, 5, 5, 10, 10, 5, 20, 5, 10, 5, 5, 5, 10, 5, 5, 10, 20, 10, 10, 20, 10, 10, 20, 5, 5, 5, 5, 10, 5, 5, 20, 20, 5, 10, 20, 10, 5, 5, 20, 5, 20, 20, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 5, 5, 20, 5, 5, 5, 10, 20, 5, 5, 5, 5, 10, 5, 10, 20, 5, 10, 5, 5, 5, 20, 5, 20, 10, 5, 5, 5, 5, 20, 5, 5, 5, 10, 5, 5, 5, 5, 10, 20, 5, 5, 5, 10, 20, 10, 10, 5, 5, 20, 20, 20, 10, 20, 20, 10, 10, 5, 5, 5, 10, 5, 20, 20, 5, 5, 20, 20, 5, 5, 20, 5, 20, 5, 5, 5, 5, 10, 5, 10, 5, 5, 10, 5, 20, 5, 5, 10, 10, 5, 10, 5, 5, 5, 5, 5, 10, 5, 5, 10, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 10, 20, 10, 5, 5, 10, 5, 5, 5, 5, 5, 10, 20, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 5, 10, 5, 10, 20, 20, 10, 5, 5, 20, 5, 10, 5, 5, 5, 5, 20, 5, 10, 20, 5, 5, 10, 20, 5, 5, 10, 10, 20, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 20, 20, 5, 5, 5, 5, 5, 5, 10, 10, 20, 5, 5, 20, 10, 5, 5, 20, 20, 20, 20, 20, 5, 20, 10, 5, 20, 5, 5, 5, 5, 10, 5, 20, 5, 5, 10, 5, 5, 10, 10, 20, 5, 5, 20, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 10, 20, 10, 20, 10, 5, 5, 5, 10, 5, 20, 20, 10, 10, 20, 20, 5, 5, 20, 5, 10, 10, 5, 5, 20, 5, 20, 5, 5, 5, 10, 5, 5, 20, 5, 10, 5, 10, 5, 10, 5, 10, 10, 5, 20, 5, 20, 5, 10, 5, 5, 5, 5, 20, 5, 20, 5, 5, 20, 10, 5, 10, 10, 5, 5, 5, 5, 10, 5, 10, 5, 10, 5, 10, 20, 5, 5, 10, 5, 10, 5, 10, 10, 20, 20, 20, 20, 10, 5, 5, 5, 20, 5, 5, 10, 10, 20, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 20, 10, 10, 10, 10, 20, 10, 5, 5, 5, 5, 10, 20, 5, 5, 5, 5, 20, 5, 5, 5, 10, 5, 5, 10, 5, 10, 10, 5, 5, 5, 5, 20, 20, 20, 5, 20, 5, 5, 10, 10, 20, 5, 5, 5, 5, 20, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 20, 10, 20, 5, 5, 5, 20, 10, 5, 10, 10, 20, 20, 5, 20, 10, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 20, 10, 5, 5, 5, 10, 20, 5, 20, 20, 5, 20, 5, 5, 10, 10, 10, 5, 5, 20, 20, 5, 5, 20, 5, 5, 10, 20, 10, 20, 5, 5, 20, 5, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 20, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 20, 5, 5, 20, 5, 10, 5, 20, 20, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 10, 10, 5, 20, 20, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 10, 20, 20, 20, 10, 10, 5, 5, 20, 10, 5, 10, 5, 5, 5, 5, 5, 20, 5, 20, 20, 5, 5, 5, 10, 5, 10, 10, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 5, 5, 10, 5, 20, 20, 5, 5, 5, 20, 5, 5, 5, 5, 10, 5, 5, 10, 5, 20, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 10, 5, 5, 5, 20, 5, 10, 5, 5, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 20, 20, 5, 5, 5, 5, 5, 10, 10, 20, 5, 5, 10, 5, 10, 20, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 20, 20, 5, 5, 5, 5, 5, 20, 5, 5, 20, 5, 10, 20, 5, 5, 5, 10, 5, 10, 5, 20, 10, 5, 10, 5, 5, 20, 20, 5, 10, 5, 5, 5, 10, 5, 5, 20, 10, 10, 20, 5, 20, 5, 5, 20, 5, 5, 10, 20, 5, 10, 20, 5, 5, 5, 5, 5, 5, 20, 5, 10, 5, 5, 20, 5, 5, 20, 5, 10, 5, 10, 10, 5, 5, 20, 5, 5, 10, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 20, 10, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 20, 20, 5, 10, 10, 20, 20, 5, 5, 5, 5, 5, 20, 20, 20, 5, 10, 5, 5, 10, 5, 20, 10, 10, 20, 5, 5, 10, 5, 5, 10, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 5, 20, 10, 5, 10, 10, 10, 10, 10, 5, 10, 5, 5, 5, 20, 10, 20, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 20, 5, 20, 5, 5, 20, 5, 5, 20, 5, 5, 5, 20, 10, 20, 5, 5, 10, 5, 5, 5, 20, 20, 5, 10, 5, 5, 20, 20, 5, 5, 5, 10, 5, 10, 5, 5, 5, 20, 10, 10, 5, 5, 5, 5, 5, 5, 5, 20, 20, 5, 20, 5, 10, 5, 20, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 20, 20, 10, 10, 5, 5, 20, 5, 10, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 20, 20, 5, 20, 5, 20, 5, 20, 5, 5, 20, 5, 5, 10, 20, 5, 20, 5, 20, 5, 5, 5, 10, 10, 5, 5, 20, 5, 5, 10, 5, 5, 10, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 10, 10, 5, 5, 5, 5, 10, 5, 10, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 10, 5, 5, 5, 10, 5, 20, 5, 20, 10, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 20, 5, 10, 5, 5, 20, 10, 5, 5, 5, 10, 10, 10, 5, 5, 5, 5, 5, 5, 20, 10, 20, 20, 5, 5, 20, 5, 5, 5, 5, 20, 5, 10, 5, 10, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 10, 5, 10, 5, 5, 20, 5, 5, 10, 5, 5, 10, 20, 10, 5, 20, 5, 5, 5, 20, 20, 5, 10, 5, 5, 5, 5, 10, 10, 10, 20, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 10, 20, 5, 20, 5, 10, 10, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 20, 5, 20, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 10, 20, 20, 5, 5, 5, 5, 5, 10, 5, 20, 20, 5, 5, 5, 20, 10, 5, 5, 5, 10, 5, 5, 5, 5, 20, 20, 5, 20, 10, 10, 20, 5, 5, 20, 5, 10, 20, 20, 10, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 20, 5, 20, 5, 5, 5, 10, 10, 20, 5, 5, 5, 5, 10, 10, 5, 20, 5, 20, 5, 5, 5, 5, 20, 5, 20, 10, 5, 20, 5, 10, 10, 5, 20, 5, 5, 5, 10, 20, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 20, 5, 20, 5, 5, 10, 20, 5, 10, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 10, 10, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 10, 20, 20, 5, 10, 20, 5, 5, 20, 10, 20, 5, 10, 5, 5, 20, 10, 5, 5, 20, 10, 5, 10, 10, 5, 5, 20, 20, 5, 20, 10, 5, 5, 5, 5, 5, 20, 5, 5, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 20, 20, 5, 20, 5, 10, 20, 5, 10, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 10, 20, 5, 5, 10, 5, 20, 20, 10, 10, 5, 5, 5, 5, 10, 20, 5, 10, 5, 20, 10, 5, 5, 20, 5, 20, 10, 5, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 20, 5, 20, 5, 5, 20, 10, 20, 5, 20, 5, 20, 5, 10, 20, 20, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 10, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 20, 20, 5, 5, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 10, 10, 20, 20, 5, 5, 5, 20, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 10, 20, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 20, 20, 5, 10, 10, 5, 5, 10, 5, 5, 20, 10, 10, 5, 5, 10, 5, 5, 20, 5, 5, 5, 5, 20, 5, 10, 10, 5, 5, 10, 20, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 10, 10, 5, 20, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 20, 5, 5, 5, 5, 5, 10, 5, 5, 5, 10, 5, 20, 20, 5, 20, 20, 20, 5, 10, 5, 5, 5, 5, 20, 20, 5, 5, 5, 10, 5, 5, 5, 10, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 20, 5, 20, 5, 20, 5, 5, 20, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 20, 20, 5, 20, 5, 10, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 20, 5, 20, 10, 10, 5, 5, 5, 10, 5, 20, 5, 20, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 20, 10, 5, 10, 5, 10, 10, 10, 5, 5, 5, 5, 5, 10, 20, 5, 5, 5, 5, 5, 20, 10, 10, 10, 5, 10, 20, 20, 20, 5, 5, 10, 10, 10, 20, 5, 20, 5, 20, 5, 5, 5, 5, 20, 5, 20, 5, 5, 20, 5, 10, 5, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 10, 5, 20, 5, 5, 5, 20, 20, 10, 5, 5, 20, 5, 10, 5, 10, 5, 5, 5, 5, 20, 5, 20, 5, 10, 20, 10, 10, 5, 5, 5, 20, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 20, 20, 5, 5, 10, 10, 10, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 20, 10, 5, 5, 5, 5, 5, 5, 20, 20, 5, 10, 5, 10, 10, 10, 10, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 5, 20, 20, 10, 20, 10, 5, 5, 5, 20, 5, 5, 5, 20, 10, 5, 10, 5, 20, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 20, 10, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 10, 10, 5, 20, 5, 5, 5, 10, 5, 5, 10, 20, 10, 5, 20, 5, 20, 5, 5, 20, 10, 5, 20, 10, 5, 5, 5, 5, 10, 20, 5, 20, 20, 5, 5, 20, 10, 5, 5, 5, 10, 5, 10, 20, 5, 5, 5, 5, 5, 10, 10, 10, 10, 5, 10, 20, 5, 5, 20, 10, 10, 10, 20, 20, 20, 5, 20, 10, 5, 5, 10, 5, 5, 10, 5, 5, 5, 10, 5, 10, 5, 20, 20, 20, 5, 10, 10, 5, 5, 10, 5, 5, 5, 10, 20, 5, 10, 10, 10, 10, 20, 20, 5, 5, 20, 5, 5, 5, 5, 10, 5, 10, 5, 10, 5, 10, 10, 20, 5, 10, 5, 10, 20, 5, 5, 5, 10, 5, 10, 5, 5, 10, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 10, 10, 5, 20, 5, 5, 5, 10, 5, 10, 20, 5, 5, 20, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 10, 20, 5, 20, 5, 10, 5, 5, 10, 5, 10, 5, 5, 5, 20, 10, 5, 5, 5, 5, 20, 10, 5, 5, 5, 5, 20, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 20, 10, 20, 5, 5, 20, 10, 5, 5, 10, 10, 10, 5, 10, 20, 5, 5, 5, 5, 10, 5, 20, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 20, 20, 5, 5, 10, 5, 5, 20, 10, 10, 5, 10, 20, 5, 10, 5, 5, 5, 10, 5, 5, 20, 5, 20, 20, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 20, 5, 5, 5, 10, 5, 10, 10, 20, 20, 5, 5, 20, 5, 10, 20, 10, 5, 5, 5, 5, 10, 5, 5, 20, 5, 5, 5, 5, 5, 5, 10, 20, 20, 5, 5, 10, 20, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 20, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 20, 10, 5, 10, 5, 5, 20, 10, 10, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 20, 10, 5, 5, 5, 20, 10, 10, 5, 5, 5, 10, 10, 5, 10, 5, 5, 5, 20, 10, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 10, 5, 5, 20, 20, 5, 20, 5, 10, 5, 10, 20, 10, 5, 10, 5, 5, 20, 5, 5, 5, 5, 20, 5, 10, 5, 5, 5, 20, 20, 5, 10, 10, 5, 10, 10, 20, 10, 5, 5, 10, 20, 5, 5, 10, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 20, 10, 10, 5, 5, 5, 20, 5, 5, 20, 10, 5, 5, 5, 10, 5, 10, 5, 5, 5, 10, 5, 5, 20, 5, 10, 5, 10, 10, 5, 5, 10, 20, 20, 5, 5, 10, 10, 10, 5, 5, 5, 10, 5, 5, 5, 10, 5, 10, 5, 10, 20, 5, 20, 10, 20, 10, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 10, 10, 5, 5, 5, 5, 10, 5, 5, 20, 20, 5, 10, 5, 5, 5, 5, 20, 5, 5, 20, 5, 10, 20, 20, 20, 5, 5, 20, 5, 10, 5, 5, 5, 5, 20, 10, 20, 10, 5, 5, 5, 10, 20, 5, 20, 5, 20, 10, 20, 20, 5, 10, 10, 5, 20, 5, 20, 5, 20, 5, 20, 5, 20, 20, 5, 5, 5, 5, 20, 20, 5, 5, 10, 5, 5, 20, 5, 5, 5, 10, 10, 5, 5, 5, 5, 5, 20, 20, 5, 10, 10, 10, 20, 5, 20, 20, 5, 5, 20, 20, 5, 5, 5, 10, 5, 20, 20, 10, 5, 5, 10, 5, 10, 10, 5, 5, 10, 5, 5, 5, 20, 5, 10, 5, 20, 5, 20, 5, 5, 20, 20, 10, 20, 5, 5, 5, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 10, 20, 5, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 10, 10, 5, 5, 20, 20, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 10, 5, 10, 10, 5, 5, 10, 10, 10, 20, 10, 10, 5, 5, 5, 10, 5, 5, 10, 10, 5, 10, 5, 5, 5, 10, 20, 5, 20, 20, 10, 5, 10, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 20, 5, 5, 20, 5, 5, 10, 20, 20, 20, 5, 5, 5, 5, 10, 10, 5, 5, 5, 5, 5, 20, 20, 5, 20, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 20, 5, 10, 20, 5, 5, 10, 5, 5, 5, 20, 20, 5, 10, 5, 10, 10, 5, 5, 10, 5, 5, 20, 20, 20, 20, 5, 5, 5, 10, 20, 10, 10, 10, 5, 10, 5, 5, 20, 5, 10, 5, 10, 5, 5, 20, 5, 5, 20, 5, 20, 5, 20, 20, 5, 20, 5, 5, 20, 5, 5, 5, 20, 5, 10, 5, 5, 20, 5, 20, 5, 20, 20, 20, 5, 5, 20, 5, 5, 10, 10, 5, 5, 5, 5, 10, 10, 5, 20, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 10, 5, 20, 5, 5, 20, 5, 10, 20, 5, 5, 10, 5, 5, 5, 5, 10, 5, 20, 5, 20, 5, 5, 5, 10, 10, 5, 5, 10, 5, 20, 20, 10, 5, 10, 5, 5, 5, 10, 5, 10, 5, 5, 10, 10, 5, 5, 20, 10, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 20, 10, 10, 20, 10, 5, 10, 5, 5, 10, 5, 10, 10, 5, 5, 20, 10, 5, 10, 5, 5, 20, 20, 5, 20, 5, 5, 5, 5, 5, 20, 10, 5, 5, 5, 10, 10, 10, 5, 5, 20, 5, 5, 10, 5, 5, 5, 20, 5, 5, 5, 10, 5, 20, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 20, 5, 5, 5, 5, 20, 5, 20, 20, 5, 5, 5, 5, 5, 10, 10, 5, 5, 5, 20, 5, 20, 10, 5, 20, 5, 5, 5, 5, 5, 5, 10, 10, 5, 10, 10, 5, 5, 20, 5, 5, 20, 20, 10, 20, 5, 10, 5, 20, 10, 10, 10, 5, 5, 10, 5, 10, 5, 20, 5, 10, 5, 5, 10, 5, 5, 5, 10, 5, 5, 10, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 5, 5, 5, 20, 10, 5, 5, 10, 5, 5, 10, 10, 20, 20, 5, 10, 10, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 10, 20, 20, 5, 5, 20, 20, 5, 10, 20, 10, 5, 5, 10, 20, 10, 5, 20, 10, 10, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 5, 10, 10, 5, 20, 20, 5, 20, 10, 5, 20, 5, 5, 5, 20, 5, 5, 20, 20, 20, 5, 20, 20, 5, 10, 5, 10, 5, 5, 5, 10, 5, 20, 10, 5, 5, 5, 5, 20, 10, 5, 10, 10, 5, 5, 5, 5, 5, 5, 20, 20, 10, 10, 5, 10, 20, 20, 5, 20, 5, 20, 10, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 10, 10, 20, 5, 5, 20, 10, 10, 5, 10, 5, 10, 5, 5, 20, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 5, 20, 5, 10, 10, 10, 5, 5, 5, 10, 5, 20, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 10, 5, 5, 10, 20, 5, 5, 10, 10, 20, 20, 20, 20, 10, 20, 5, 5, 5, 5, 5, 5, 5, 20, 5, 10, 5, 10, 20, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 20, 20, 20, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 10, 5, 10, 10, 5, 5, 20, 20, 10, 5, 10, 10, 20, 10, 5, 5, 10, 10, 5, 10, 5, 5, 5, 10, 5, 5, 10, 10, 10, 5, 20, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 10, 10, 5, 5, 5, 20, 10, 5, 5, 10, 20, 20, 20, 5, 10, 10, 20, 20, 5, 20, 5, 5, 20, 5, 10, 5, 20, 20, 10, 5, 5, 10, 5, 5, 5, 10, 5, 5, 10, 10, 5, 20, 5, 10, 10, 5, 5, 10, 10, 5, 5, 5, 5, 10, 5, 10, 20, 5, 5, 10, 5, 20, 5, 20, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 20, 20, 20, 5, 20, 5, 20, 10, 5, 5, 5, 5, 5, 5, 20, 5, 20, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 5, 5, 10, 5, 5, 10, 20, 5, 20, 5, 10, 5, 20, 20, 10, 20, 5, 10, 5, 5, 10, 10, 20, 5, 20, 5, 20, 5, 20, 20, 20, 5, 20, 5, 20, 5, 5, 10, 20, 5, 10, 5, 5, 10, 5, 5, 20, 10, 10, 10, 5, 5, 5, 5, 5, 10, 5, 10, 10, 20, 5, 5, 5, 5, 5, 10, 10, 10, 5, 10, 20, 20, 5, 5, 20, 20, 5, 20, 5, 5, 5, 10, 10, 5, 5, 5, 10, 20, 5, 10, 5, 5, 10, 5, 10, 5, 10, 10, 5, 20, 5, 5, 10, 5, 5, 10, 10, 20, 5, 20, 20, 20, 5, 5, 10, 20, 5, 20, 5, 20, 5, 5, 10, 5, 20, 10, 20, 5, 10, 5, 10, 10, 5, 20, 5, 20, 5, 5, 5, 10, 5, 5, 20, 5, 5, 5, 5, 5, 10, 10, 20, 5, 20, 20, 5, 5, 10, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 10, 20, 5, 5, 5, 10, 5, 20, 5, 10, 5, 5, 10, 5, 5, 5, 10, 10, 5, 5, 10, 5, 5, 20, 20, 20, 5, 5, 20, 20, 10, 5, 5, 10, 5, 5, 5, 20, 5, 5, 20, 5, 20, 5, 20, 5, 5, 5, 10, 5, 20, 20, 5, 10, 10, 5, 5, 5, 5, 5, 5, 10, 20, 5, 5, 5, 20, 5, 5, 5, 20, 5, 5, 5, 5, 10, 20, 10, 5, 5, 5, 10, 5, 20, 20, 10, 10, 5, 10, 5, 20, 20, 5, 5, 5, 10, 5, 20, 5, 5, 20, 5, 5, 10, 20, 5, 20, 20, 5, 5, 20, 20, 20, 20, 5, 5, 10, 5, 20, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 20, 20, 20, 5, 5, 10, 5, 5, 10, 5, 5, 20, 5, 10, 5, 10, 10, 5, 5, 20, 5, 10, 20, 5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 10, 5, 5, 10, 10, 5, 5, 20, 5, 10, 5, 20, 5, 20, 20, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 10, 20, 10, 5, 20, 20, 10, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 20, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 10, 5, 5, 10, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 20, 20, 5, 5, 20, 20, 10, 5, 10, 5, 10, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5, 10, 10, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 20, 5, 20, 5, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 20, 5, 10, 5, 5, 20, 5, 5, 5, 5, 5, 10, 10, 10, 5, 5, 5, 10, 10, 5, 20, 5, 10, 5, 5, 5, 5, 20, 20, 20, 5, 5, 5, 20, 20, 10, 5, 5, 5, 10, 5, 5, 5, 5, 5, 20, 5, 5, 20, 5, 10, 20, 5, 10, 5, 10, 10, 10, 10, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 5, 20, 5, 5, 5, 20, 5, 5, 5, 5, 5, 10, 10, 5, 5, 5, 5, 5, 20, 10, 10, 5, 10, 10, 20, 10, 5, 20, 10, 10, 5, 5, 20, 5, 5, 5, 5, 20, 5, 5, 5, 5, 10, 20, 5, 20, 20, 5, 20, 5, 10, 10, 5, 5, 10, 20, 5, 5, 5, 5, 20, 20, 5, 5, 5, 5, 10, 5, 5, 10, 5, 5, 5, 5, 5, 10, 5, 5, 10, 5, 10, 10, 10, 10, 5, 20, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 10, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 10, 10, 5, 5, 5, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 5, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 20, 20, 5, 20, 20, 10, 10, 5, 5, 5, 5, 10, 10, 5, 10, 5, 10, 10, 5, 20, 5, 5, 20, 5, 5, 10, 5, 20, 5, 5, 5, 5, 20, 5, 5, 20, 5, 10, 5, 5, 20, 10, 10, 20, 10, 20, 20, 10, 20, 5, 10, 5, 20, 10, 5, 10, 5, 5, 10, 5, 5, 20, 5, 5, 10, 10, 10, 5, 5, 20, 5, 5, 5, 20, 5, 10, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 5, 5, 5, 20, 5, 20, 10, 10, 20, 20, 5, 20, 20, 10, 20, 5, 5, 5, 20, 5, 5, 5, 5, 20, 5, 10, 5, 10, 5, 5, 5, 20, 20, 5, 5, 10, 20, 10, 5, 5, 5, 10, 10, 5, 10, 20, 10, 10, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 20, 20, 5, 5, 5, 20, 20, 5, 5, 20, 5, 10, 20, 20, 5, 20, 10, 10, 5, 5, 5, 10, 5, 10, 5, 5, 5, 20, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 10, 10, 10, 5, 10, 5, 5, 5, 20, 20, 20, 5, 5, 5, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 10, 10, 5, 10, 20, 5, 10, 20, 10, 5, 5, 5, 5, 20, 5, 10, 5, 20, 5, 5, 5, 20, 5, 5, 10, 5, 5, 10, 5, 10, 10, 5, 5, 5, 5, 20, 5, 20, 20, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 10, 10, 5, 5, 5, 20, 5, 5, 5, 20, 10, 20, 5, 5, 20, 10, 5, 5, 5, 20, 10, 5, 20, 5, 5, 5, 20, 5, 5, 5, 20, 5, 20, 5, 10, 5, 5, 10, 10, 10, 10, 5, 5, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 20, 5, 5, 20, 5, 5, 5, 5, 20, 5, 5, 10, 10, 5, 5, 5, 5, 10, 5, 5, 20, 5, 5, 5, 20, 5, 5, 5, 5, 20, 10, 5, 5, 5, 5, 10, 5, 5, 10, 20, 5, 5, 20, 5, 10, 5, 5, 20, 10, 5, 5, 20, 10, 20, 20, 5, 5, 20, 10, 10, 20, 5, 20, 5, 10, 10, 10, 5, 10, 5, 10, 5, 5, 5, 10, 5, 5, 10, 5, 5, 20, 20, 10, 10, 5, 5, 10, 20, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 20, 5, 5, 5, 20, 5, 20, 5, 5, 5, 10, 5, 10, 20, 5, 20, 5, 10, 20, 10, 5, 5, 20, 10, 5, 10, 5, 10, 20, 20, 5, 20, 5, 5, 10, 5, 10, 20, 10, 20, 10, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 10, 10, 5, 20, 5, 5, 5, 20, 10, 5, 10, 5, 5, 5, 5, 5, 10, 10, 5, 5, 10, 20, 20, 20, 5, 10, 5, 5, 5, 20, 5, 5, 5, 20, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 20, 5, 20, 5, 5, 5, 5, 20, 20, 20, 5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 10, 20, 5, 5, 5, 20, 5, 5, 10, 20, 20, 10, 5, 5, 5, 5, 20, 5, 5, 20, 20, 5, 5, 10, 20, 5, 5, 20, 5, 5, 10, 5, 10, 5, 10, 20, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 20, 20, 20, 5, 5, 5, 5, 10, 20, 5, 10, 20, 5, 5, 5, 10, 20, 5, 10, 5, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 20, 5, 20, 5, 20, 10, 10, 5, 5, 20, 5, 5, 5, 5, 20, 20, 5, 5, 20, 20, 5, 5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 20, 10, 10, 5, 10, 10, 5, 20, 5, 5, 5, 5, 10, 5, 20, 20, 5, 5, 10, 10, 20, 20, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 20, 5, 5, 10, 10, 20, 5, 20, 5, 20, 10, 5, 20, 10, 5, 10, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5, 5, 20, 10, 10, 5, 10, 10, 5, 10, 5, 5, 5, 10, 10, 5, 5, 20, 10, 10, 10, 5, 5, 20, 5, 5, 20, 5, 5, 5, 20, 5, 5, 5, 10, 10, 5, 5, 5, 20, 20, 20, 5, 20, 5, 20, 5, 10, 5, 5, 5, 20, 5, 20, 10, 20, 5, 10, 5, 5, 20, 5, 5, 20, 10, 5, 5, 5, 5, 10, 10, 5, 5, 20, 20, 5, 10, 20, 5, 10, 5, 20, 5, 5, 10, 10, 5, 5, 5, 20, 5, 5, 5, 5, 10, 20, 5, 10, 5, 20, 5, 5, 5, 10, 5, 5, 5, 5, 20, 20, 5, 5, 10, 20, 5, 5, 5, 20, 5, 5, 10, 5, 10, 20, 10, 20, 10, 20, 5, 5, 20, 5, 5, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 20, 5, 20, 10, 5, 10, 10, 20, 10, 20, 5, 10, 10, 20, 5, 5, 5, 5, 5, 5, 5, 20, 20, 5, 20, 20, 20, 5, 5, 5, 5, 10, 5, 5, 5, 5, 20, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 10, 5, 20, 10, 20, 10, 20, 5, 5, 5, 20, 5, 5, 5, 20, 10, 20, 5, 5, 5, 20, 5, 5, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 5, 20, 20, 5, 5, 5, 5, 5, 5, 5, 5, 20, 10, 5, 5, 20, 5, 5, 20, 20, 20, 5, 10, 10, 5, 5, 5, 5, 10, 20, 10, 10, 5, 5, 5, 5, 5, 20, 10, 5, 20, 10, 5, 10, 5, 5, 20, 5, 5, 5, 10, 5, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 10, 5, 10, 10, 5, 5, 5, 20, 5, 5, 10, 5, 5, 5, 20, 20, 20, 20, 5, 5, 5, 5, 10, 5, 20, 5, 5, 20, 20, 5, 5, 20, 10, 10, 5, 5, 5, 20, 5, 5, 5, 5, 5, 10, 5, 20, 20, 5, 5, 5, 10, 20, 5, 20, 5, 20, 5, 5, 5, 5, 5, 5, 5, 20, 20, 20, 5, 5, 20, 20, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 20, 10, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 10, 5, 5, 10, 10, 5, 10, 10, 5, 5, 20, 20, 5, 5, 5, 5, 5, 10, 5, 20, 10, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 20, 20, 5, 20, 5, 20, 20, 20, 10, 20, 10, 5, 5, 10, 10, 20, 5, 5, 5, 5, 5, 10, 5, 10, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 20, 20, 20, 10, 5, 5, 10, 5, 5, 10, 5, 5, 20, 10, 20, 5, 5, 20, 20, 10, 20, 20, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 10, 5, 10, 5, 20, 20, 10, 10, 5, 5, 20, 10, 5, 10, 10, 5, 5, 5, 5, 10, 5, 5, 20, 5, 5, 5, 5, 10, 5, 10, 5, 10, 5, 5, 5, 5, 10, 5, 5, 20, 5, 5, 5, 5, 5, 10, 20, 5, 10, 5, 10, 20, 10, 20, 20, 5, 5, 5, 5, 5, 20, 5, 10, 10, 5, 20, 5, 20, 10, 20, 10, 5, 10, 5, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 5, 10, 10, 20, 5, 20, 5, 5, 20, 5, 20, 5, 5, 5, 20, 10, 10, 5, 5, 5, 5, 5, 20, 10, 10, 5, 5, 5, 20, 10, 5, 10, 5, 5, 20, 10, 5, 5, 5, 5, 5, 5, 20, 5, 20, 5, 10, 10, 5, 5, 5, 5, 10, 5, 5, 5, 5, 10, 5, 10, 5, 10, 5, 10, 5, 5, 5, 5, 20, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 10, 5, 5, 10, 5, 20, 5, 5, 5, 10, 10, 5, 20, 5, 5, 10, 5, 5, 10, 20, 5, 5, 5, 5, 10, 20, 20, 20, 5, 5, 10, 20, 5, 5, 5, 10, 5, 20, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 20, 5, 20, 5, 10, 5, 20, 20, 10, 10, 5, 5, 10, 5, 5, 5, 5, 5, 5, 10, 20, 10, 10, 5, 5, 5, 5, 5, 20, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 20, 10, 20, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 10, 20, 10, 20, 5, 10, 5, 5, 5, 5, 5, 5, 10, 10, 5, 5, 10, 20, 10, 5, 5, 5, 5, 20, 5, 5, 20, 5, 5, 10, 5, 5, 5, 5, 5, 5, 10, 20, 5, 20, 20, 10, 10, 10, 20, 10, 20, 5, 5, 10, 10, 5, 20, 5, 5, 10, 5, 5, 5, 5, 5, 5, 5, 10, 20, 10, 10, 5, 10, 20, 5, 5, 20, 5, 10, 5, 5, 10, 5, 20, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 20, 5, 5, 20, 10, 5, 5, 20, 5, 5, 5, 5, 20, 20, 5, 10, 5, 20, 5, 5, 5, 5, 5, 5, 20, 10, 20, 20, 10, 5, 5, 5, 5, 5, 5, 20, 5, 10, 5, 5, 5, 5, 5, 10, 5, 5, 5, 20, 20, 5, 10, 20, 20, 20, 10, 20, 5, 5, 5, 5, 20, 5, 5, 5, 5, 20, 5, 5, 5, 5, 20, 5, 20, 5, 5, 5, 5, 5, 5, 10, 5, 5, 5, 5, 5, 10, 5, 10, 5, 10, 5, 5, 20, 10, 20, 10, 20, 5, 5, 5, 5, 5, 10, 20, 10, 20, 20, 10, 5, 5, 10, 5, 5, 10};
    cout << s.lemonadeChange(bills2);
    return 0;
}