#include <iostream>
using namespace std;

int main() {
    int n = 0, h = 0;
    cin >> n >> h;
    int cnt = 0; // 统计幸运币
    int cnt_t2 = 0; // 统计幸运一掷, 可以翻盘的机会
    // 先不考虑随机伤害, 先考虑稳定伤害
    // 如果稳定伤害足够将 BOSS 击杀, 则随机伤害对结果无影响
    // 否则, 考虑 BOSS 所剩血量在随机伤害的次数下死亡的概率
    int x = 0, t = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t >> x;
        if (1 == t) {
            cnt += x;
        } else {
            h -= x;
            x = 0; // 消耗
            ++cnt_t2;
        }
    }
    if (h <= 0) {
        cout << "100%" << endl;
    } else {
        // 让 cnt_t2 个由 1~6 伤害组成的最终伤害 >= BOSS 所剩血量即可
        // 假设 BOSS 还有 10 滴血, 还有 3 次机会
        // 就是 3 次从 1~6 中选一个数, 使之总和大于等于 BOSS 血量
        // 每一次掷出点数概率为 1/6
        // 反正所有概率相等, 所以不必进行细化
        // 直接就是随机伤害次数乘上 1/6 既是答案
        // 同时也需要考虑如果每次都很幸运, 抽到的全是 6, 也不能击杀 BOSS 所剩血量的情况
        if (cnt_t2 * 6 < h) {
            cout << "0%" << endl;
            return 0;
        }
        cout << ((double)cnt_t2 * 1.0 / 6.0) * 100 << "%" << endl;
    }
    return 0;
}