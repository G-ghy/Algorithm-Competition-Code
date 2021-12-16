#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>

using namespace std;

constexpr int N = 2e5 + 10;

int n, m, k;
int p[N];
int c[N]; // color
vector<vector<int>> pos = vector<vector<int>>(N);
int cnt[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i) {
        cin >> c[i];
        p[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int pl = find(l), pr = find(r);
        if (pl != pr) p[pl] = pr;
    }

    for (int i = 1; i <= n; ++i) {
        int pi = find(i);
        pos[pi].push_back(i);
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (!pos[i].empty()) {
            // memset(cnt, 0, sizeof cnt);
            for (int j = 0; j < pos[i].size(); ++j) ++cnt[c[pos[i][j]]];
            int maxx = -0x3f3f3f3f;
            for (int j = 0; j < pos[i].size(); ++j) maxx = max(maxx, cnt[c[pos[i][j]]]);
            res += pos[i].size() - maxx;
            for (int j = 0; j < pos[i].size(); ++j) --cnt[c[pos[i][j]]];
        }

    cout << res << endl;
}
int main() {
    solve();
    return 0;
}

/**
 * 最开始有一种错误的思路是统计颜色最多的有多少个，最终答案是其余颜色的气球数量
 * 不过想到这题不可能这么简单，发现一种情况是，只需要保证被询问到的两个点颜色相同即可，如果这些询问里面有些点之间根本没被问道则不需要相同颜色
 * 然后发现，如果把被询问到的点放入一个集合中，最后是好多个集合，只需要保证集合内部颜色相同即可，所以也就是并查集的应用了
 * 
 * 不过统计答案的方式可能比较差，导致了超时
 * 
 * 保证并查集内部的是同一个颜色即可
 * 首先把气球分类，然后对于并查集内部的统计哪个颜色的气球数量最多，需要进行染色的气球数量为并查集内其余气球数量
 * 
 * 思路是正确的，不过TLE了
 */