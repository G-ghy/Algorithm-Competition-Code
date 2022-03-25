#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
using PII = pair<int, int>;

constexpr int N = 150000;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int dis[N];
bool st[N];
int h[N], e[N], ne[N], w[N], idx;
priority_queue<PII, vector<PII>, greater<PII>> heap;


void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
void dijkstra(int u) {
    memset(dis, 0x3f, sizeof dis);
    dis[u] = 0;
    heap.emplace(dis[u], u);

    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int ver = t.second;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int p = e[i];
            if (dis[p] > dis[ver] + w[i]) {
                dis[p] = dis[ver] + w[i];
                heap.emplace(dis[p], p);
            }
        }
    }
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    dijkstra(1);

    if (dis[n] == INF) cout << -1 << '\n';
    else cout << dis[n] << '\n';
}
int main() {
    solve();
    return 0;
}