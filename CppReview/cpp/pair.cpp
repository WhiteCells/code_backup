#include <iostream>
#include <vector>


void UsePair() {

    std::pair<int, int> p2 = std::make_pair<int, int>(1, 2);

    auto p1 = std::make_pair<int>(1, 2);
    auto p3 = std::pair<int, int>({ 1, 2 });

    std::cout << p1.first << " " << p1.second << '\n';
    std::cout << p2.first << " " << p2.second << '\n';
    std::cout << p3.first << " " << p3.second << '\n';


    std::vector<std::pair<int, int>> v;
    v.push_back(std::pair<int, int>({ 1, 2 }));
    v.push_back(std::make_pair<int, int>(2, 3));
    v.push_back(std::make_pair<int>(2, 3));
    for (auto& p : v) {
        std::cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    UsePair();
    return 0;
}