#include <iostream>

using namespace std;

auto fun() -> int {
    return 10101.11;
}

auto fun2() -> pair<int, int> {
    return { 1, 2 };
}

pair<int, int> fun3() {
    return { 1, 2 };
}


auto main() -> int {
    cout << fun() << '\n';
    cout << fun2().first << " " << fun2().second << '\n';
    cout << fun3().first << " " << fun3().second << '\n';
}