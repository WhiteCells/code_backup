/*
https://ac.nowcoder.com/acm/contest/67159/F
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, T;
    // n 地区数
    // m 被破坏的传送门个数
    // T 正常传送门的耗时
    cin >> n >> m >> T;
    vector<vector<int>> mp(n + 1, vector<int>(n + 1, T)); // 破坏的传送门
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        mp[a][b] = t;
        mp[b][a] = t;
    }
    for (int k = 1; k <= n; ++k) {
        mp[k][k] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    cout << mp[1][n] << endl;
    return 0;
}