// 使用并查集将具有约束条件的各云朵合并为一个商品
// 然后采用01背包计算一定范围价格内的最大价值
// 需要注意的是01背包如果采用量两维数组会MLE，需要采取优化版本
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

constexpr int N = 1e4 + 10;
constexpr int INF = 0x3f3f3f3f;

struct {
    int price, value;
} cloud[N], block[N];

int n, m, w;
int p[N];
int dp[N];
// int dp[N][N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve() {
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i) p[i] = i;
    for (int i = 1; i <= n; ++i) {
        int price, value;
        cin >> price >> value;
        cloud[i] = {price, value};
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (pa != pb) p[pa] = pb;
    }

    for (int i = 1; i <= n; ++i) {
        int pi = find(i);
        block[pi].price += cloud[i].price;
        block[pi].value += cloud[i].value;
    }


    // int cnt = 0;
    // for (int i = 1; i <= n; ++i)
    //     if (p[i] == i) {
    //         ++cnt;
    //         for (int j = 0; j <= w; ++j) {
    //             dp[cnt][j] = dp[cnt - 1][j];
    //             if (j >= block[i].price) 
    //                 dp[cnt][j] = max(dp[cnt][j], dp[cnt - 1][j - block[i].price] + block[i].value);
    //         }
    //     }
    
    // 由于采用1维，自然也就不需要cnt的存在了
    for (int i = 1; i <= n; ++i)
        if (p[i] == i) {
            for (int j = w; j >= block[i].price; --j)
                dp[j] = max(dp[j], dp[j - block[i].price] + block[i].value);
        }

    cout << dp[w] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}