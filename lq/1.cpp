#include <iostream>
using namespace std;

int main() {
    int n = 0, q = 0, res = 1;
    cin >> n >> q;
    string s[q];
    for (int i = 0; i < q; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); ++j) {
            if ('L' == s[i][j]) {
                res = res * 2 - 1;
            }
            else {
                res *= 2;
            }
        }
        cout << res << endl;
        res = 1;
    }
    return 0;
}