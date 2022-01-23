/**
 * 如果在对题目理解没错的情况下
 * 
 * 一种猜测是：
 * 显然图中包含多个连通块
 * 对每个连通块求一个异或和
 * 在所有连通块的异或和中取max为答案
 * 
 * 为什么会有这样的想法：
 * 1. 可以发现，小数a & 大数b，结果c一定满足 c <= min(a, b)
 * 2. a & a = a
 * 
 * 因此拿小的数据去和其他数据进行&一定会使答案更优
 */

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

constexpr int N = 5e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int w[N], p[N], v[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) p[i] = i;
    fill(v, v + n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (pa != pb) p[pa] = pb;
    }

    for (int i = 1; i <= n; ++i) {
        int pi = find(i);
        if (v[pi] == -1) v[pi] = w[i];
        else v[pi] &= w[i];
    }

    int res = -1;
    for (int i = 1; i <= n; ++i)
        if (v[i] != -1) res = max(res, v[i]);

    cout << res << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}