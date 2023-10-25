#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;

// 把一个正整数 n 分解成 m 个不同的整整数之和
// 排在后面的数大于前面倒数, 输出所有方案
void dfs(int n, int m, int start) {
    if (n == 0 && m == path.size()) {
        res.push_back(path);
        return;
    }
    for (int i = start; i <= n; ++i) {
        path.push_back(i);
        dfs(n - i, m, i + 1);
        path.pop_back();
    }
}


int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    dfs(n, m, 1);
    for (const auto &v : res) {
        for (const auto &ele : v) {
            cout << ele << ' ';
        }
        cout << '\n';
    }
    return 0;
}