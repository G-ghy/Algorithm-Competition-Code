// 本来一眼蹬是二分，但是发现题目中给的范围是有绝对值的，因此想到了画图，本来还担心是dp，结果发现就是找在哪点处覆盖的区间最多，不难想到前缀和和差分
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

constexpr int offset = 1e6, N = 1e6 + 10;

int n, p;
int f[3 * N];

inline void insert(int l, int r, int v) {
    f[l] += v;
    f[r + 1] -= v;
}
void solve() {
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        insert(a - p + offset, a + p + offset, 1);
    }

    int maxx = 0;
    for (int i = 0; i < 3 * N; ++i) {
        f[i] += f[i - 1];
        maxx = max(maxx, f[i]);
    }

    printf("%d\n", maxx);
}
int main() {
    solve();
    return 0;
}