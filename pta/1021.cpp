// 最常规的写法是并查集先判断一下是否有解
// 然后dfs每一个点同时维护最大路径值和和该路径值对应的点
// pat上就这么写就够了，下面那种比较让人眼前一亮的性质面对pat上的数据并没有非常好的表现

// 常规写法，真的离谱，总觉得这么简单暴力的写法应该过不了，没想到就是这么做
// 写之前我一想直接dfs每一个点找到最长距离并同时维护点集，觉得太暴力应该有更好的方法，没想到这样就可以过
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

constexpr int N = 1e4 + 10, M = N * 2;
constexpr int INF = 0x3f3f3f3f;

int n;
int h[N], e[M], ne[M], idx;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int dfs(int p, int preP) {
    int len = 0;
    for (int i = h[p]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == preP) continue;
        len = max(len ,dfs(j, p));
    }
    return len + 1;
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n;
    int k = n; // 连通块数量
    for (int i = 1; i <= n; ++i) p[i] = i;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        int px = find(x), py = find(y);
        if (px != py) {
            p[px] = py;
            --k;
        }
        add(x, y); add(y, x);
    }
    if (k > 1) cout << "Error: " << k <<  " components" << endl;
    else {
        vector<int> point;
        int maxLen = 0;
        for (int i = 1; i <= n; ++i) {
            int len = dfs(i, -1);
            if (len > maxLen) {
                maxLen = len;
                point.clear();
                point.push_back(i);
            } else if (len == maxLen) {
                point.push_back(i);
            }
        }

        for (int p : point) cout << p << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
// 性质1：只有度数为1的点才有可能是答案，因为度数不为1的点如果通过某一个邻接点一定可以获取更优解
// 对应的解决思路是在读入边时维护点的度数，找到度数为1的点进行dfs
// 
// 但是我的最初想法是有没有可能通过一次遍历找到最大深度
//
// 题目抽象：让人眼前一亮的方法找到树中所有最长路
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <cmath>
// #include <unordered_map>
// #include <set>

// using namespace std;

// constexpr int N = 1e4 + 10, M = N * 2; // 注意是树结构
// constexpr int INF = 0x3f3f3f3f;

// int n;
// int p[N];
// int h[N], e[M], ne[M], idx;

// int maxLen;
// // vector<int> point, tmp;
// int point[N], cnt, cntTmp;

// int find(int x) {
//     if (p[x] != x) p[x] = find(p[x]);
//     return p[x];
// }
// void add(int a, int b) {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }
// void dfs(int x, int pre, int len, int inx) {
//     bool flag = true; // 是否无路可走了
//     for (int i = h[x]; ~i; i = ne[i]) {
//         int j = e[i];
//         if (j == pre) continue;
//         flag = false; // 还有路可走
//         dfs(j, x, len + 1, inx);
//     }
//     if (flag) {
//         if (len > maxLen) {
//             maxLen = len;
//             if (inx == 1) cnt = 0;
//             else cnt = cntTmp;
//             point[cnt++] = x;
//         } else if (len == maxLen) {
//             point[cnt++] = x;
//         }
//     }
// }
// void solve() {
//     memset(h, -1, sizeof h);
//     cin >> n;
//     int k = n; // 连通块数量
//     for (int i = 1; i <= n; ++i) p[i] = i;
//     for (int i = 0; i < n - 1; ++i) {
//         int x, y;
//         cin >> x >> y;
//         int px = find(x), py = find(y);
//         if (px != py) {
//             p[px] = py;
//             --k;
//         }
//         add(x, y); add(y, x);
//     }
//     if (k > 1) cout << "Error: " << k <<  " components" << endl;
//     else {
//         maxLen = 0;
//         dfs(1, 0, 1, 1); // 找到最长度一端的所有端点
//         cntTmp = cnt;
//         for (int i = 0; i < cntTmp; ++i) dfs(point[i], 0, 1, 2); // 找到最长路的另一个端点
        
//         sort(point, point + cnt);

//         for (int i = 0; i < cnt; ++i) {
//             if (i && point[i] == point[i - 1]) continue;
//             cout << point[i] << endl;
//         }
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     solve();
//     return 0;
// }

// 说明：
// 1. n个点 m条边
// 2. 点的编号为1~n
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <cmath>
// #include <unordered_map>

// using namespace std;

// int n, m; // n:点数; m:边数
// int cnt; // 连通块数量
// vector<int> p; // 并查集father数组

// int find(int x) {
//     if (p[x] != x) p[x] = find(p[x]);
//     return p[x];
// }
// void solve() {
//     cin >> n >> m;

//     cnt = n; // 初始连通块数量
//     p = vector<int>(n);
//     for (int i = 1; i <= n; ++i) p[i] = i; // 初始化并查集数组

//     for (int i = 0; i < m; ++i) {
//         int x, y;
//         cin >> x >> y;
//         int px = find(x), py = find(y);
//         if (px != py) {
//             p[px] = py;
//             --cnt;
//         }
//     }

//     cout << cnt << endl;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     solve();
//     return 0;
// }