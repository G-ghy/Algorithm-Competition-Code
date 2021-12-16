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

constexpr int N = 5e5 + 10, M = 5e5 + 10;
constexpr int INF = 0x3f3f3f3f;

struct Edge {
    int a, b, w;
}edges[M];
int cnt;

int n, m;
int a[N];
int p[N]; // 并查集
bool st[N];
int res;

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void kruskal() {
    res = 0;
    memset(st, 0, sizeof st);
    for (int i = 1; i <= n; ++i) p[i] = i;
    sort (edges, edges + m, [](Edge &a, Edge &b) -> bool {return a.w < b.w;});

    for (int i = 0; i < cnt; ++i) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int pa = find(a), pb = find(b);

        if (pa != pb) {
            p[pa] = pb;
            res += w;
            st[i] = true;
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[cnt++] = {a, b, w};
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    // 加入其他边

    kruskal();

    cout << res << endl;
    for (int i = 0; i < cnt; ++i)
        if (st[i]) cout << edges[i].a << ' ' << edges[i].b << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// 边数太大，根本存不下
// 两个最小生成树算法的时间复杂度都不能满足要求
// 是需要前期做一些处理吗？在最小生成树上套了啥子东西？