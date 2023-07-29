#include <iostream>

#include <unordered_set>

void UseMulitSet() {
    // auto hash = [&](const std::pair<int, int>& p) {
    //     return p.first ^ p.first;
    // };
    // std::unordered_set<std::pair<int, int>, decltype(hash)> s(hash);

    struct Hash {
        size_t operator()(const std::pair<int, int>& p) const {
            return p.first ^ p.second;
        }
    };
    std::unordered_set<std::pair<int, int>, Hash> s(Hash);

}

int main() {
    return 0;
}