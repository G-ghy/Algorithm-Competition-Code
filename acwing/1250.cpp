#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 45000;

int n, m;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
inline int getId(int x, int y) {
    return x * n + y;
}
void solve() {
    cin >> n >> m;
    for (int i = n + 1; i <= n * n + n; ++i) p[i] = i;
    
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y, a, b;
        char direction;
        cin >> x >> y >> direction;

        if (direction == 'D') a = x + 1, b = y;
        else a = x, b = y + 1;

        int inx_xy = getId(x, y), inx_ab = getId(a, b);
        int pinx_xy = find(inx_xy), pinx_ab = find(inx_ab);

        if (!res && pinx_xy == pinx_ab) res = i;
        else p[pinx_xy] = pinx_ab;
    }

    if (res) cout << res << '\n';
    else cout << "draw\n";
}
int main() {
    solve();
    return 0;
}