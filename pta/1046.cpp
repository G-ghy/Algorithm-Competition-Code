// 很明显的前缀和
// 但是由于成环，所以一个路径需要算两个方向，比如2 5，需要考虑2到5，也需要考虑5到2
// 2到5显然前缀和就可以算了，关键在于5到2如何计算，可以发现5到2需要再从1开始计算，所以不妨在5后面再放一组1到5，这样也可以用前缀和做了
// 而空间上仅需要1e5的空间扩大一倍，即2e5，是完全可以的
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

int n;
int f[N];

inline int count(int l, int r) {
    if (r < l) r += n;
    return f[r - 1] - f[l - 1];
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> f[i];
    for (int i = 1, j = n + 1; i <= n; ++i, ++j) f[j] = f[i];
    for (int i = 1; i <= 2 * n; ++i) f[i] += f[i - 1];

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << min(count(l, r), count(r, l)) << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}