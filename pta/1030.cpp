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

constexpr int N = 510, M = N * N;
constexpr int INF = 0x3f3f3f3f;

int n, m, sp, ep;
int h[N], e[M], ne[M], d[M], c[M], idx;
int dis[N];
bool st[N];
int minDis, minCost;
vector<int> path, res;

void add(int a, int b, int dis, int cost) {
    e[idx] = b;
    ne[idx] = h[a];
    d[idx] = dis;
    c[idx] = cost;
    h[a] = idx++;
}
void dfs(int x, int pre, int dis, int cost) {
    if (dis > minDis) return; // 剪枝
    path.push_back(x);
    if (x == ep) {
        if (cost < minCost) {
            minCost = cost;
            res = path;
        }
        path.pop_back();
        return;
    }
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == pre) continue;
        dfs(j, x, dis + d[i], cost + c[i]);
    }
    path.pop_back();
    return;
}
void dijkstart() {
    priority_queue<pair<int, int>> heap;
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);
    dis[sp] = 0;
    heap.emplace(0, sp);

    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int ver = t.second;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dis[j] > dis[ver] + d[i]) {
                dis[j] = dis[ver] + d[i];
                heap.emplace(dis[j], j);
            }
        }
    }
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m >> sp >> ep;
    for (int i = 0; i < m; ++i) {
        int a, b, dis, cost;
        cin >> a >> b >> dis >> cost;
        add(a, b, dis, cost);
        add(b, a, dis, cost);
    }

    dijkstart();
    minDis = dis[ep];

    minCost = INF;
    dfs(sp, -1, 0, 0);

    for (int p : res) cout << p << ' ';
    cout << minDis << ' ' << minCost << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}