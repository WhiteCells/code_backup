#include "../head-file.h"

/*
problme:

url:
 */

// time complexity: O()
// spatial complexity: O()
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> v;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                string subs(s.begin() + i, s.begin() + j + 1);
                // cout << subs << endl;
                int cnt = 0;
                for (const auto &c : subs) {
                    if ('1' == c) {
                        ++cnt;
                    }
                }
                if (k == cnt) {
                    v.emplace_back(subs);
                }
            }
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            int n = min(a.size(), b.size());
            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i]) {
                    return a[i] < b[i];
                }
            }
            return a.size() > b.size() ? true : false;
        });
        // for (auto &ele : v) {
        //     cout << ele << endl;
        // }
        return v.empty() ? "" : v[v.size() - 1];
    }
};


int main() {
    // string s = "100011001";
    // int k = 3;
    // string s = "11000111";
    // int k = 1;
    // string s = "111111110010001010";
    // int k = 11;
    string s = "001110101101101111";
    int k = 10;
    cout << Solution().shortestBeautifulSubstring(s, k) << '\n';
    return 0;
}