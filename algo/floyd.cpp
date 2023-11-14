#include<iostream>
#include<vector>
using namespace std;

const int INF = 100000000;

void floyd(vector<vector<int>> &distmap, vector<vector<int>> &path) {
    const int NODE = distmap.size(); // 用邻接矩阵的大小传递顶点个数，减少参数传递
    path.assign(NODE, vector<int>(NODE, -1)); // 初始化路径数组
    // 对于每一个中转点
    for (int k = 1; k != NODE; ++k) {
        // 枚举源点
        for (int i = 0; i != NODE; ++i) {
            // 枚举终点
            for (int j=0; j!= NODE; ++j) {
                // 不满足三角不等式
                if (distmap[i][j]>distmap[i][k]+distmap[k][j]) {
                    distmap[i][j]=distmap[i][k]+distmap[k][j]; // 更新
                    path[i][j]=k; //记录路径
                }
            }
        }
    }
}

void print(const int &beg, const int &end, const vector<vector<int> > &path) {
    if (path[beg][end]>=0) {
        print(beg, path[beg][end], path);
        print(path[beg][end], end, path);
    } else {
        cout<<"->"<<end;
    }
}

int main() {
    int n_num, e_num, beg, end;//含义见下
    cout<<"（不处理负权回路）输入点数、边数：";
    cin>>n_num>>e_num;
    vector<vector<int> > path, distmap(n_num, vector<int>(n_num, INF));//默认初始化邻接矩阵
    for (int i=0, p, q; i!=e_num; ++i) {
        cout<<"输入第"<<i+1<<"条边的起点、终点、长度（100000000代表无穷大，不联通）：";
        cin>>p>>q;
        cin>>distmap[p][q];
    }
    floyd(distmap, path);
    cout<<"计算完毕，可以开始查询，请输入出发点和终点：";
    cin>>beg>>end;
    cout<<"最短距离为"<<distmap[beg][end]<<"，打印路径："<<beg;
    print(beg, end, path);
}

// n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4