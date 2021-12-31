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

constexpr int N = 4e4 + 500;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);

    return p[x];
}
void solve() {
    cin >> n >> m;
    for (int i = n + 1; i <= n * n + n; ++i) p[i] = i;
    
    int res = -1;
    for (int i = 1; i <= m; ++i) {
        int x, y, a, b;
        char direction;
        cin >> x >> y >> direction;

        if (direction == 'D') a = x + 1, b = y;
        else a = x, b = y + 1;

        int inx_xy = x * n + y, inx_ab = a * n + b;
        int pinx_xy = find(inx_xy), pinx_ab = find(inx_ab);

        if (pinx_xy == pinx_ab) {
            res = i;
            break;
        }
        p[pinx_xy] = pinx_ab;
    }
    if (res != -1) cout << res << '\n';
    else cout << "draw\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}