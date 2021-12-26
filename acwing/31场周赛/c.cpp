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
#include <bitset>

using namespace std;
using LL = long long;

constexpr int N = 1010;
constexpr int INF = 0x3f3f3f3f;

struct Circle {
    int r, a, b;
} cs[N];
int n, m, k;
// int g[N][N];
bitset<N> g[N], t;
pair<int, int> ps[N];

inline bool pInC(pair<int, int> p, Circle c) {
    LL x = p.first, y = p.second;
    LL r = c.r, a = c.a, b = c.b;

    return (x - a) * (x - a) + (y - b) * (y - b) < r * r;
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        ps[i] = {x, y};
    }
    for (int i = 1; i <= m; ++i) {
        int r, a, b;
        cin >> r >> a >> b;
        cs[i] = {r, a, b};
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (pInC(ps[i], cs[j]))
                // g[i][j]  = 1;
                g[i] |= 1 << j;

    while (k--) {
        int p1, p2;
        cin >> p1 >> p2;
        t = g[p1] ^ g[p2];
        // for (int i = 0; i < N; ++i)
        //     if (g[p1][i] != g[p2][i]) ++res;
        cout << t.count() << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}