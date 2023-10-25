#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> res;
vector<int> path;
vector<int> vist;
int n = 0;

void dfs() {
    if (path.size() == n) {
        res.push_back(path);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vist[i]) {
            path.push_back(i);
            vist[i] = true;
            dfs();
            path.pop_back();
            vist[i] = false;
        }
    }
}

int main() {
    cin >> n;
    vist.resize(n + 1, false);
    dfs();
    
    for (const auto &v : res) {
        for (const auto &ele : v) {
            cout << setw(5) << ele;
        }
        cout << '\n';
    }
    return 0;
}

// #include <iomanip>
// #include <iostream>
// using namespace std;
// int n;
// bool vis[50];  // 访问标记数组
// int a[50];     // 排列数组，按顺序储存当前搜索结果
// 
// void dfs(int step) {
//   if (step == n + 1) {  // 边界
//     for (int i = 1; i <= n; i++) {
//       cout << setw(5) << a[i];  // 保留5个场宽
//     }
//     cout << endl;
//     return;
//   }
//   for (int i = 1; i <= n; i++) {
//     if (vis[i] == 0) {  // 判断数字i是否在正在进行的全排列中
//       vis[i] = 1;
//       a[step] = i;
//       dfs(step + 1);
//       vis[i] = 0;  // 这一步不使用该数 置0后允许下一步使用
//     }
//   }
//   return;
// }
// 
// int main() {
//   cin >> n;
//   dfs(1);
//   return 0;
// }
