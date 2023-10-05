#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void UseLambda() {
    auto f = [](int a) {
        return a;
    };
}

class Solution3 {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> menm(n, vector<int>(2, -1));
        function<int(int, bool)> dfs = [&](int i, bool hold)->int {
            if (i < 0) {
                return hold ? INT_MIN : 0;
            }
            if (-1 == menm[i][hold]) {
                return menm[i][hold];
            }
            if (hold) {
                return menm[i][hold] = max(dfs(i - 1, true), dfs(i - 1, false) - prices[i]);
            }
            return menm[i][hold] = max(dfs(i - 1, false), dfs(i - 1, true) + prices[i]);
        };
        return dfs(n - 1, false);
    }
};

int main()
{
    /* code */
    return 0;
}
