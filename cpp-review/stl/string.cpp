#include <iostream>

#include <string>

void UseString() {
    std::string s;
    s.append("s");
    s.append("a");
    s.append("D");
    int a = 1;
    // s.append(a);
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
    std::string s{ "hello" };
    std::cout << typeid(s[0]).name() << ' ' << typeid(char).name() << '\n';
}

int main() {
    // UseString();
    // StringReadRow();
    StringType();
    return 0;
}