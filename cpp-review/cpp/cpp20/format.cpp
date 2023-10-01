#include <iostream>
#include <tuple>
#include <format>
#include <map>

int main() {
    std::tuple<int, std::string> tp{ std::pair<int, std::string>(1, "test") };
    std::cout << std::format("{},{}", std::get<0>(tp), std::get<1>(tp));
    std::map<int, std::string> m;
    m.emplace(std::make_pair(1, "sn"));
    m.emplace(std::make_pair(2, "s"));
    for (const auto [_, ele] : m) {
        std::cout << ele << ' ';
    }
    return 0;
}