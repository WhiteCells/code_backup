#include "../../head-file.h"

/*
problme: 

url: 
 */

// time complexity: O()
// spatial complexity: O()
class RangeModule {
public:
    RangeModule() {
        s.clear();
        m.clear();
        left_inte = false;
        right_inte = false;
    }
    
    void addRange(int left, int right) {        
        if (!queryRange(left, right)) {
            // 区间之间有交集
            if (left_inte) {
                // 左区间存在
                 
            } else if (right_inte) {
                   
            }
            // 区间之间无交集
            s.emplace(left, right);
            m.emplace(left, right);
        }
    }
    
    bool queryRange(int left, int right) {
        // 找到第一个 >= left 的下标
        auto left_it = m.lower_bound(left);
        // 如果找到的区间左端点 <= right 则说明区间重合
        if (m.find(left_it->first) != m.end() && m.at(left_it->first) <= right) {
            cout << left_it->first << " " << left_it->second << endl;
            return true;
        }
        // auto right_it = m.lower_bound(right);
    }
    
    void removeRange(int left, int right) {
        if (queryRange(left, right)) {
            // 区间存在
            
        }
    }
private:
    set<pair<int, int>> s;
    map<int, int> m;
    bool left_inte, right_inte;
};

int main() {
    RangeModule r;
    r.addRange(10, 20);
    r.queryRange(10, 20);
    return 0;
}