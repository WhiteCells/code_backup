/*
https://ac.nowcoder.com/acm/contest/67159/A
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int T = 0;
    cin >> T;
    for (int k = 0; k < T; ++k) {
        int n = 0, res = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a = 0;
            cin >> a;
            v.push_back(a);
        }
        if (1 == v.size()) {
            if (0 == v[0] % 3) {
                cout << v[0] << endl;
            } else {
                cout << "-1" << endl;
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v.size(); ++j) {
                if (i == j) {
                    continue;
                }
                
            }
        }
    }

}