#include "../head-file.h"
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.70%)
 * Likes:    6720
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 3.9M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 *
 *
 */

// @lc code=start
class Solution {
public:
    bool ItSAPalindromeString(string& s, int i, int j) {
        if (i == j) {
            return true;
        }
        string s1, s2;
        if ((j - i + 1) & 1) {
            s1 = string(s.begin() + i, s.begin() + (i + j) / 2);
            s2 = string(s.begin() + (i + j) / 2 + 1, s.begin() + j + 1);
        }
        else {
            s1 = string(s.begin() + i, s.begin() + (i + j) / 2 + 1);
            s2 = string(s.begin() + (i + j) / 2 + 1, s.begin() + j + 1);
        }
        for (int k = 0; k < s2.size() / 2; ++k) {
            char tmp = s2[k];
            s2[k] = s2[s2.size() - k - 1];
            s2[s2.size() - k - 1] = tmp;
        }
        return s1 == s2;
    }
    string longestPalindrome(string s) {
        int len = 0;
        string ret;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                if (ItSAPalindromeString(s, i, j)) {
                    if (j - i + 1 > len) {
                        ret = string(s.begin() + i, s.begin() + j + 1);
                        len = j - i + 1;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end


int main() {
    // string s = "babad";
    // string s = "cbbd";
    string s = "aaaa";
    cout << Solution().longestPalindrome(s) << '\n';
    return 0;
}