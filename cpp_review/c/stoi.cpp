#include <iostream>
#include <string>
#include <cmath>

template <class T>
T Stoi1(const std::string& s) {
    T res = 0;
    int s_len = s.size();
    int i = 0;
    bool flag = true;
    if ('-' == s[0]) {
        i = 1;
        flag = false;
    }
    for (; i < s_len; ++i) {
        int num = s[i] - '0';
        res = res * 10 + num;
        // res += res * 10 + (s[i] - '0');
    }
    return flag ? res : -res;
}

void TestStoi1() {
    std::string s;
    s = "-1441341432";
    std::cout << s << '\n';
    std::cout << Stoi1<int>(s) << '\n';
}

template <class T>
T Stoi2(const std::string& s) {
    T res = 0;
    int s_len = s.size();
    bool flag = true;
    int end_index = 0;
    if ('-' == s[0]) {
        end_index = 1;
        flag = false;
    }
    for (int i = s_len - 1, j = 0; i >= end_index; --i, ++j) {
        int num = s[i] - '0';
        res += num * pow(10, j);
        // res += (s[i] - '0') * pow(10, j);
    }
    return flag ? res : -res;
}

void TestStoi2() {
    std::string s;
    s = "-1441341432";
    std::cout << s << '\n';
    std::cout << Stoi2<int>(s) << '\n';
}

int main() {
    // TestStoi1();
    TestStoi2();
    return 0;
}