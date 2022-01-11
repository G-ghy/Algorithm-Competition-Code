// 另外两种做法
// 1. 双端队列bfs，向1块内的点X的距离为0，向.的距离为1，求出从1块到2块的最短距离
// 2. 遍历1块和2块的所有点对，取最小曼哈顿距离
//      单从两个点来说，图上的最短距离不一定是曼哈顿距离，因为点点之间的曼哈顿路径之间可能有障碍物
//      所谓障碍物，是指X，但是如果两个点之间存在障碍物，那么将起点和终点做出修改显然可以得到更短的答案
//      也就是说对于非最近的两个点对，直接计算曼哈顿距离不正确，但是对于距离最近的两个点对，直接计算曼哈顿距离一定是正确的
//      需要说明的是这种方法是n^2的，与我下面的想法相比未必会更快，而且这个思路是需要证明的，未必想得出
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

constexpr int N = 60;
constexpr int INF = 0x3f3f3f3f;

int n, m;
char g[N][N];
int label[N][N], idx;
bool st[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int minStep;
int step[N][N];

inline void bfs(int x, int y, int idx) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    st[x][y] = true;
    label[x][y] = idx;

    while (q.size()) {
        auto t = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int a = t.first + dx[i], b = t.second + dy[i];

            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b] || g[a][b] == '.') continue;
            q.emplace(a, b);
            st[a][b] = true;
            label[a][b] = idx;
        }
    }
}
inline void find(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    st[x][y] = true;
    step[x][y] = 0;
    
    while (q.size()) {
        auto t = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b] || label[a][b] == 1) continue;
            step[a][b] = min(step[a][b], step[t.first][t.second] + 1);
            if (label[a][b] == 2) {
                minStep = min(minStep, step[a][b]);
                return;
            }
            q.emplace(a, b);
            st[a][b] = true;
        }
    }

}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> g[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] == 'X' && !st[i][j]) bfs(i, j, ++idx);
    

    minStep = INF;
    memset(step, 0x3f, sizeof step);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] == 'X' && label[i][j] == 1) {
                memset(st, 0, sizeof st);
                find(i, j);
            }

    cout << (minStep - 1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}