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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int a[N], b[N];
int v[N];
int res = 0;

void dfs(int p, int x, int l, int len) {
    x ^= v[p];
    if (l == len) {
        res += x;
        x ^= v[p];
        return;
    }
    for (int i = p + 1; i <= n; ++i)
        dfs(i, x, l + 1, len);
    x ^= v[p];
    return;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        // 不说后面的逻辑是不是正确，l和r的范围是2e5，那个数能有这么多位
        for (int j = l; j <= r; ++j)
            a[i] |= 1 << j;
        b[i] = x;
    }

    for (int i = 1; i <= m; ++i)    
        for (int j = i + 1; j <= m; ++j) {
            a[i] ^= a[j];
            b[i] ^= b[j];
        }

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= 30; ++j)
            if ((a[i] >> j) & 1) {
                v[j] = b[i];
                break;
            }
    
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            dfs(j, 0, 0, i);
    }

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}