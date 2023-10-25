#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;

void dfs(vector<int> path, int start, int cnt, int sum, int n) {
    if (0 == cnt && sum == n) {
        res.push_back(path);
        return;
    }
    if (sum > n) {
        return;
    }
    for (int i = start; i < n; ++i) {
        sum += i;
        path.push_back(i);
        --cnt;
        dfs(path, i + 1, cnt, sum, n);
        sum -= i;
        path.pop_back();
        ++cnt;
    }
}

int main() {
    int n = 0;
    cin >> n;
    // 把一个正整数 n 分解成 m 个不同的整整数, 排在后面的数大于前面倒数, 输出所有方案
    vector<int> path;
    dfs(path, 1, 3, 0, n);
    for (const auto &ele : res) {
        for (const auto &val : ele) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}