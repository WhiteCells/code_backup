#include "../head-file.h"

/*
problme:

url:
 */

// time complexity: O()
// spatial complexity: O()
class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &values) {
        if (!values[0]) {
            return 0;
        }
        int n = edges.size();
        vector<int> cnt(n + 1); // 统计 i 有多少个孩子
        for (const auto &edge : edges) {
            ++cnt[edge[0]];
        }
        for (auto &s : cnt) {
            if (0 == s) {
                s = 1;
            }
        }
        long long res = 0;
        int m = values.size();
        for (int i = 1; i < m; ++i) {
            res += cnt[i] * values[i];
        }
        return res;
    }
};

int main() {
    // vector<vector<int>> edges { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 2, 4 }, { 4, 5 } };
    // vector<int> values { 5, 2, 5, 2, 1, 1 };
    vector<vector<int>> edges { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 1, 4 }, { 2, 5 }, { 2, 6 } };
    vector<int> values { 20, 10, 9, 7, 4, 3, 5 };

    cout << Solution().maximumScoreAfterOperations(edges, values) << endl;
    return 0;
}

