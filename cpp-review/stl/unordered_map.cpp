#include <iostream>
#include <vector>

#include <unordered_map>


/*
使用哈希表去重 (1, 0),(0, 1) (x, y) (y, x)
将 x, y 映射到 x * n + y

 */
void UnorderedMap() {
    std::vector<std::vector<int>> edges {
        { 1, 0 },
        { 0, 1 },
        { -1, 0 },
        { 0, -1 },
        { 1000, 200 },
        { 200, 1000 },
    };
    int n = edges.size();
    std::unordered_map<int, int> m;
    for (const auto& edge : edges) {
        int x = edge[0], y = edge[1];
        if (x > y) {
            std::swap(x, y);
        }
        ++m[x * n + y];
    }
    for (const auto& ele : m) {
        std::cout << ele.first << " " << ele.second << '\n';
    }
}

int main() {
    UnorderedMap();
    return 0;
}