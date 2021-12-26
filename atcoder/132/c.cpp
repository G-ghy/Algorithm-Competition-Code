// 正解估计有排列组合，当n过大且均为-1时总方案数是阶乘，搜索会超时
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

constexpr int N = 510;
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 998244353;

int n, d;
bool st[N];
int inx[N], inxcnt;
int num[N], numcnt;
int res;

void dfs(int loca) {
    if (loca == inxcnt) {
        res = (res + 1) % mod;
        return;
    }

    // 枚举第loca个-1处放置哪个值从0到numcnt-1选择一个未选过的
    for (int i = 0; i < numcnt; ++i) {
        if (st[i] || abs(num[i] - inx[loca]) > d) continue;
        st[i] = true;
        dfs(loca + 1);
        st[i] = false;
    }
}
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x == -1) inx[inxcnt++] = i;
        else st[x] = true;
    }
    for (int i = 1; i <= n; ++i)
        if (!st[i]) num[numcnt++] = i;

    memset(st, 0, sizeof st);
    res = 0;
    dfs(0);

    cout << (res % mod) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}