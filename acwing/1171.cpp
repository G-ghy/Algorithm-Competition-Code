#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

constexpr int N = 1e4 + 10, M = 2 * N;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int depth[N], f[N][14], dis[N][14];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
void bfs(int u) {
    queue<int> q;
    q.push(u);
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0;
    depth[u] = 1;

    while (q.size()) {
        int t = q.front(); q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int p = e[i];
            if (depth[p] == INF) {
                q.push(p);
                depth[p] = depth[t] + 1;

                f[p][0] = t;
                dis[p][0] = w[i];
                for (int k = 1; k <= 13; ++k) {
                    f[p][k] = f[f[p][k - 1]][k - 1];
                    dis[p][k] = dis[p][k - 1] + dis[f[p][k - 1]][k - 1];
                }
            }
        }
    }
}

// 先把a跳到和b同层
// 然后两者一起向上跳到lca的下一层
int getDis(int a, int b) {
    int res = 0;

    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 13; ~k; --k)
        if (depth[f[a][k]] >= depth[b]) {
            res += dis[a][k];
            a = f[a][k];
        }
    if (a == b) return res;
    for (int k = 13; ~k; --k)
        if (f[a][k] != f[b][k]) {
            res += dis[a][k] + dis[b][k];
            a = f[a][k];
            b = f[b][k];
        }
    res += dis[a][0] + dis[b][0];
    return res;
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    bfs(1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << getDis(a, b) << '\n';
    }
}
int main() {
    solve();
    return 0;
}