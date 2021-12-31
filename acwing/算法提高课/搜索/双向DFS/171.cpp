// 如果w的范围比较小，是01背包问题
// 搜索每个物品，枚举选或不选，记录当前搬动的总重量。
// 搜素空间大小为(2^46 - 1) * 2，常规搜索会超时

// 假设物品为a，b，c，d
// 常规搜索到一组物品为a，b，d，总重量和为w[a] + w[b] + w[d]
// 如果预先处理出w[a] + w[b]的值，则a，b，d这一组实际只需要枚举一次d即可计算得出重量和
// 按照这个思路，考虑把所有物品分为2部分，
// 首先预处理第一部分各个选法的重量和，之后枚举另一部分的各个选法，在第一部分预处理结果中找到<=最大重量限制-第2部分重量且最大的值
// 二分找到的第1部分中的结果+第2部分枚举的值即为一个合法解，找到最大的合法解即为答案
// 这样做正确的原因在于我们考虑的一种选法的重量和，即通过所有部分和可以计算得出总重量和，因此可以对搜索序列进行拆分
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

constexpr int N = 50;
constexpr int INF = 0x3f3f3f3f;

int n, m; // n个物品，最大搬动重量为m
int w[N]; // 每个物品重量
int weight[(1 << 23) + 10], cnt; // 对第1部分的各个选法，预处理出其重量和，注意数组大小
int res;

// 对第1部分的预处理
void dfs1(int u, int s, int k) { // 当前搜索第u个物品，当前总重量为s，需要搜索到第k个物品
    if (u == k) {
        weight[cnt++] = s;
        return;
    }
    dfs1(u + 1, s, k); // 不拿第u个物品
    if (w[u] <= m - s) dfs1(u + 1, s + w[u], k); // 拿第u个物品
}
// 对第2部分进行dfs
void dfs2(int u, int s, int k) {
    if (u == k) {
        int l = 0, r = cnt - 1; // 去weight中二分查找目标值
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (weight[mid] <= m - s) l = mid;
            else r = mid - 1;
        }
        if (weight[l] <= m - s)
            res = max(res, s + weight[l]);
        return;
    }
    dfs2(u + 1, s, k); // 不拿第u个物品
    if (w[u] <= m - s) dfs2(u + 1, s + w[u], k);
}
void solve() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) cin >> w[i];

    // 优化搜索顺序，优先枚举大的会减少搜索分支数量
    sort(w, w + n, [](int a, int b) -> bool {return a > b;});

    int k = n >> 1;
    dfs1(0, 0, k);

    sort(weight, weight + cnt); // 由于第2部分在dfs时需要对weight进行二分查找，需要排序

    res = 0;
    dfs2(k, 0, n);

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}