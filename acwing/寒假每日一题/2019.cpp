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

constexpr int N = 2010;
constexpr int INF = 0x3f3f3f3f;

int sp, ep;
int g[N][N];
bool st[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dis[N][N];

// 需要注意题目中说到起点(sp, ep)是在图的中心，
// 图的坐标范围是横坐标:[0, 2 * sp], 纵坐标: [0, 2 * ep]
void solve() {
    int n;
    cin >> n >> sp >> ep;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }

    memset(dis, 0x3f, sizeof dis);
    dis[sp][ep] = 0;
    deque<pair<int, int>> q;
    q.emplace_back(sp, ep);

    while (q.size()) {
        auto t = q.front(); q.pop_front();

        for (int i = 0; i < 4; ++i) {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a > 2 * sp || b < 0 || b > 2 * ep) continue;
            if (dis[a][b] > dis[t.first][t.second] + g[a][b]) {
                dis[a][b] = dis[t.first][t.second] + g[a][b];
                if (g[a][b]) q.emplace_back(a, b);
                else q.emplace_front(a, b);
            }
        }
    }

    cout << dis[1][1] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}