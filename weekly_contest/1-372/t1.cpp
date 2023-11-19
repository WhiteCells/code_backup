#include "../../head-file.h"

/*
problme: 

url: 
 */

// time complexity: O()
// spatial complexity: O()
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if (s1[0] != s2[0] || s1[0] != s3[0] || s2[0] != s3[0]) {
            return -1;
        }
        // 找出公共部分
        int mp[26] {};
        for (const auto &c : s1) {
            mp[c - 'a']++;
        }
        for (const auto &c : s2) {
            mp[c - 'a']++;
        }
        for (const auto &c : s3) {
            mp[c - 'a']++;
        }
        int mp2[26] {};
        for (int i = 0; i < 26; ++i) {
            if (3 <= mp[i]) {
                mp2[i] = 1;
            }
        }
        string s11, s22, s33;
        for (const auto &c : s1) {
            if (mp2[c - 'a']) {
                s11 += c;
            }
        }
        for (const auto &c : s2) {
            if (mp2[c - 'a']) {
                s22 += c;
            }
        }
        for (const auto &c : s3) {
            if (mp2[c - 'a']) {
                s33 += c;
            }
        }
        if (s11 != s22 || s22 != s33) {
            return -1;
        }
        // s1 中找公共部分需要多久
        int j = 0, k = 0, m = 0;
        for (int i = 0; i < s11.size(); ++i) {
            for (int z = i; z < s1.size(); ++z) {
                if (s1[z] == s11[i]) {
                    j += z - i;
                    break;
                }
            }
        }

        //
        for (int i = 0; i < s11.size(); ++i) {
            for (int z = i; z < s1.size(); ++z) {
                if (s2[z] == s11[i]) {
                    k += z - i;
                    break;
                }
            }
        }

        for (int i = 0; i < s11.size(); ++i) {
            for (int z = i; z < s1.size(); ++z) {
                if (s3[z] == s11[i]) {
                    m += z - i;
                    break;
                }
            }
        }
        return j + k + m;
    }
};

int main() {
    // s1 = "abc"，s2 = "abb"，s3 = "ab"
    string s1 = "abc", s2 = "abb", s3 = "ab";
    cout << Solution().findMinimumOperations(s1, s2, s3) << endl;
    return 0;
}