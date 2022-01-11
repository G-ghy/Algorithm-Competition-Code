#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

constexpr int N = 2e5 + 10, M = 1e6 + 9e5;
constexpr int INF = 0x3f3f3f3f;

int n, m, k;
int h[N], e[M], ne[M], idx;
int dis[N];
bool st[N], vis[N];

// 对于所有非标记点
// 是否存在某个点能够以一个相同的距离到达所有标记点
// 通过引入虚拟源点(向所有非标记点引边)可以简化上述过程的代码操作流程
// 认为最终集合点为虚拟源点，所以以虚拟源点为起点跑一次dijkstra记录从起点到各个标记点最短距离的操作
// 最小回合数应当为上述求解的起点距离各标记点距离的最短距离的最大值
// 检查虚拟源点距离各标记点的距离与最小回合数的差值，差值必须为2的倍数才合法，因为一次冗余操作至少需要走2条边(多走一个点至少需要2条边)

// 如果冗余操作一次多走2步的判断是正确的，那么之前想法的错误之处在于选择最短路径进行判断
// 因为从虚拟源点到各个标记点的路径有多条，未必就是通过最短路径加上冗余操作到达的
inline void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
inline void dijkstra(int u) {
    priority_queue<pair<int, int>> heap;
    dis[u] = 0;
    heap.emplace(dis[u], u);
    

    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int ver = t.second;

        if (vis[ver]) continue;
        vis[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dis[j] > dis[ver] + 1) {
                dis[j] = dis[ver] + 1;
                heap.emplace(dis[j], j);
            }
        }
    }
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        add(u, v); add(v, u);
    }
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        st[x] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!st[i]) {
            add(0, i);
            add(i, 0);
        }

    memset(dis, 0x3f, sizeof dis);
    dijkstra(0);

    int round = 0;
    for (int i = 1; i <= n; ++i)
        if (st[i]) round = max(round, dis[i]);

    // for (int i = 1; i <= n; ++i) cout << i << ' ' << dis[i] << endl;
    bool flag = true;
    if (round == INF) flag = false;
    else {
        for (int i = 1; i <= n; ++i)
        if (st[i] && ((round - dis[i]) % 2)) {
            flag = false;
            break;
        }
    }
    
    cout << (flag ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}