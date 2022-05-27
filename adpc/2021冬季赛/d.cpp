// #include <cstring>
// #include <cstdio>
// #include <cmath>
// #include <iostream>
// #include<string>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <stack>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;

// constexpr int N = 1e5 + 10;
// constexpr int INF = 0x3f3f3f3f;

// int n, m, t;
// int h[N], e[N], ne[N], w[N], idx;
// int sum[N];

// void add(int a, int b, int c) {
//     e[idx] = b;
//     w[idx] = c;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }
// vector<int> init(int u) {
//     vector<int> d = vector<int>(N, 0);
//     for (int i = h[u]; i != -1; i = ne[i]) {
//         int p = e[i], v = w[i];
//         init(p);
//         if (!d[v]) sum[u] += sum[p] + v * v;
//         // else sum[u] += sum[p] + 2 * v * (v * d[v]) + v * v;
//         else sum[u] += (sum[p] - (v * d[v]) * (v * d[v])) + (v * (d[v] + 1)) * (v * (d[v] + 1));
//         ++d[v];
//     }
//     return d;
// }
// void solve() {
//     memset(h, -1, sizeof h);
//     cin >> m >> t >> n;
//     for (int i = 0; i < m - 1; ++i) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         add(a, b, c);
//     }

//     init(1);
    
//     for (int i = 1; i <= n; ++i) cout << i << ": " << sum[i] << '\n';
//     // while (t--) {
//     //     int x;
//     //     cin >> x;
//     //     cout << sum[x] << '\n';
//     // }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;

// g[u]: 存储与 u 相邻的结点
vector<int> g[N];

// sz: 子树大小
// big: 重儿子
// col: 结点颜色
// L[u]: 结点 u 的 DFS 序
// R[u]: 结点 u 子树中结点的 DFS 序的最大值
// Node[i]: DFS 序为 i 的结点
// ans: 存答案
// cnt[i]: 颜色为 i 的结点个数
// totColor: 目前出现过的颜色个数
int sz[N], big[N], col[N], L[N], R[N], Node[N], totdfn;
int ans[N], cnt[N], totColor;

void add(int u) {
  if (cnt[col[u]] == 0) ++totColor;
  cnt[col[u]]++;
}

void del(int u) {
  cnt[col[u]]--;
  if (cnt[col[u]] == 0) --totColor;
}

int getAns() { return totColor; }

void dfs0(int u, int p) {
  L[u] = ++totdfn;
  Node[totdfn] = u;
  sz[u] = 1;
  for (int v : g[u])
    if (v != p) {
      dfs0(v, u);
      sz[u] += sz[v];
      if (!big[u] || sz[big[u]] < sz[v]) big[u] = v;
    }
  R[u] = totdfn;
}

void dfs1(int u, int p, bool keep) {
  // 计算轻儿子的答案
  for (int v : g[u])
    if (v != p && v != big[u]) {
      dfs1(v, u, false);
    }
  // 计算重儿子答案并保留计算过程中的数据（用于继承）
  if (big[u]) {
    dfs1(big[u], u, true);
  }
  for (int v : g[u])
    if (v != p && v != big[u]) {
      // 子树结点的 DFS 序构成一段连续区间，可以直接遍历
      for (int i = L[v]; i <= R[v]; i++) {
        add(Node[i]);
      }
    }
  add(u);
  ans[u] = getAns();
  if (keep == false) {
    for (int i = L[u]; i <= R[u]; i++) {
      del(Node[i]);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &col[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs0(1, 0);
  dfs1(1, 0, false);
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}