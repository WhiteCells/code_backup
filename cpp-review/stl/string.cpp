#include <iostream>
#include <vector>

#include <string>

void UseString() {
    std::string s;
    s.append("s");
    s.append("a");
    s.append("D");
    int a = 1;
    // s.append(a); // append 参数 string
    s.push_back(a + '0');
    std::cout << s << '\n';
    std::string s1 = "123";
    std::string s2 = "11";
    const char* s3 = "123";
    std::cout << std::to_string(std::atoi(s1.c_str()) + std::atoi(s2.c_str()));
}


void StringReadRow() {
    std::string s;
    std::getline(std::cin, s); // read a row
    std::cout << s << '\n';
}


void StringType() {
    std::string s { "hello" };
    std::cout << typeid(s[0]).name() << ' ' << typeid(char).name() << '\n';
}

void StringFind() {
    std::string s { "test*/int a" };
    std::string s2;
    if (s.find("*/") != std::string::npos) {
        s2 = std::string(s.begin() + s.find("*/") + 2, s.end());
    }
    std::cout << s2 << '\n';
    if (s[0] == s[3] == 't') {
        std::cout << "1" << '\n';
    }
    if (s[0] == s[3]) {
        std::cout << "2" << '\n';
    }
    if ('t' == s[0] && 't' == s[3]) {
        std::cout << "3" << '\n';
    }
}

void InterceptString() {
    std::string s = "hello";
    if ("hel" == std::string(s.begin(), s.begin() + 3)) {
        std::cout << "1" << '\n';
    }
}

int main() {
    // UseString();
    // StringReadRow();
    // StringType();
    // StringFind();
    InterceptString();
    return 0;
}