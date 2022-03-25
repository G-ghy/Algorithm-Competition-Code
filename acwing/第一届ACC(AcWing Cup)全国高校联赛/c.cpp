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
using LL = long long;

constexpr int N = 5010;
constexpr int INF = 0x3f3f3f3f;

int n, m, k;
LL a[N];
LL dp[N][N];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    // 本质是01背包，但是f[i][j]的含义为：以第i个数字结尾的
    // 约束区间的最后一个数据，而非指定区间的第一个数据
    // 划分集合，如果划定的区间中不包含第i个数据，则f[i][j] = f[i - 1][j]
    // 否则，f[i][j] = f[i - m][j - 1]，如果区间中包含第i个数据，则i-1，i-2，... i-m+1均处在区间中，因此要从f[i-m]开始
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0 && i - m + 1>= 1) dp[i][j] = max(dp[i][j],  dp[i - m][j - 1] + a[i] - a[i - m]);
        }

    // 通过这句找到了 i - m >= 1的错误
    // for (int i = 1; i <= n; ++i) cout << i << ' ' << dp[i][1] << endl;
    cout << dp[n][k] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}