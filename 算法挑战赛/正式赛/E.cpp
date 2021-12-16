/**
 * 由于可以进行任意次调整，因此顺序是任意的
 * 只需考虑一种最优顺序即可
 * 我考虑的是贪心，结果一看标签给的是01背包
 * 
 * 伤害就是背包问题中的价值，去掉人数等价于占用背包容量
 */

#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

constexpr int N = 50;

int n;
int v[N], w[N];
int f[N][N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> w[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }

    cout << f[n][n] << endl;
}
int main()
{
    solve();

    return 0;
}