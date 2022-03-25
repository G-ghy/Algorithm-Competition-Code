#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

constexpr int N = 2010, M = 10010;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dis[N];
int cnt[N];
bool st[N];
queue<int> q;

void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
bool spfa() {
    for (int i = 1; i <= n; ++i) {
        q.push(i);
        st[i] = true;
    }

    while (q.size()) {
        int t = q.front(); q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int p = e[i];
            if (dis[p] > dis[t] + w[i]) {
                dis[p] = dis[t] + w[i];
                cnt[p] = cnt[t] + 1;
                if (cnt[p] >= n) return true;
                if (!st[p]) {
                    q.push(p);
                    st[p] = true;
                }
            }
        }
    }

    return false;
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << (spfa() ? "Yes" : "No") << '\n';
}
int main() {
    solve();
    return 0;
}