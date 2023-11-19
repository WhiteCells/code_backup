/*
https://ac.nowcoder.com/acm/contest/67159/B
 */

#include <iostream>
using namespace std;

constexpr int mod = 1e9 + 7;

// n 中选 m 个 的组合
long long getCombin(int n, int m) {
    // 分母
    int d = 1;
    for (int i = 0; i < n; ++i) {
        d *= (n - i);
        d %= mod;
    }
    // 分子
    int mo = 1;
    for (int i = 0; i < m; ++i) {
        mo *= (m - i);
        mo %= mod;
    }
    return d / mo;
}

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    long long res = 0;
    for (int m = 1; m <= n; ++m) {
        if (m == x || m == y || m == z) {
            continue;
        }
        res += getCombin(n, m);
        res %= mod;
    }
    cout << res << endl;
    return 0;
}