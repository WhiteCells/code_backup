#include "../head-file.h"

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            int j = i;
            for (; j < n - 1; ++j) {
                if (s[j] == s[j + 1]) {
                    ++cnt;
                }
                if (cnt > 1) {
                    break;
                }
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main() {
    string s = "52233";
    cout << Solution().longestSemiRepetitiveSubstring(s) << endl;
    return 0;
}