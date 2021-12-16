// f[i][j]
// 状态表示：前i个轮此，出牌总和模k之后的值为j的所有选法
// 属性：方案数
// 状态计算：集合划分，按照前i-1个轮此的出牌值进行划分，分成0到49
// 这道题显然dfs是行不通的，一看数据就可以算出来了，没有其他好办法，真的去考虑下dp
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

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = 1e9 + 7;

int n, m, mod;
int a[N];
int f[N][N];

inline bool check(int x) {
    while (x) {
        if (x % 10 == 7 || x % 10 == 9) return true;
        x /= 10;
    }
    return false;
}
void solve() {
    cin >> n >> m >> mod;
    for (int i = 1; i <= m; ++i) cin >> a[i];

    for (int i = 1; i <= m; ++i) ++f[1][a[i] % mod];
    // 第i轮，出牌分值为j的方案数
    for (int i = 2; i <= n; ++i) // 第i轮
        for (int j = 0; j < 50; ++j) // 第i轮的分值
            for (int c = 0; c < 50; ++c) // 第i-1轮的分值
                for (int k = 1; k <= m; ++k) { // 枚举第i轮出第几张牌
                    if ((c + a[k]) % mod == j)
                        f[i][j] = (f[i][j] + f[i - 1][c]) % MOD;
                }
    
    int res = 0;
    for (int i = 0; i < 50; ++i)
        if (check(i % mod))
            res = (res + f[n][i]) %  MOD;
    
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}