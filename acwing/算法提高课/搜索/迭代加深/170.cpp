// 常规dfs，确定每个位置应当填写的数值
// 由于dfs只能去搜索可行解，而不能确定当前解是否为最终解，即当前的长度未必是最短的，后续可能有更短的序列，因此需要搜索所有情况维护最短序列
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

int res[N]; // 记录答案
int path[N], cnt; // 记录中间过程
int minStep; // 可行序列的最短长度

void dfs(int u, int n) {
    bool st[N] = {0};
    
    if (u >= minStep) return;
    if (path[u - 1] == n) {
        if (u < minStep) {
            minStep = u;
            memcpy(res, path, sizeof path);
        }
        return;
    }
    
    for (int i = 0; i < u; ++i)
        for (int j = i; ~j; --j) {
            int s = path[i] + path[j];
            // 1. 比最大值大 s > n0000
            // 2. 不能保证严格递增 s <= path[u - 1]
            // 3. 已经搜索过了 st[s]
            // 以上情况不需要再搜索了
            if (s > n || s <= path[u - 1] || st[s]) continue;
            st[s] = true;
            path[cnt++] = s;
            dfs(u + 1, n);
            --cnt;
            // st不需要还原的原因
            // st标记的是对于下面这种情况
            // path[0]->path[3]依次为1 2 3 4
            // 在搜索dfs(5, n)时，1+4 == 2+3，如果不标记就会搜索2次5，显然这2次是重复的
            // 我最开始担心的是对于 1 2 3 5 和 1 2 4 5，如果在1 2 4 5时把5标记了，那么1 2 3 5这种情况就会直接忽略了
            // 但是1 2 4 5 和 1 2 3 5是两种情况，在进入5这一层时st都会初始化为全0
        }
}
void solve(int n) {
    path[cnt++] = 1;
    dfs(1, n);
    for (int i = 0; i < minStep; ++i) cout << res[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    while (cin >> n, n) {
        minStep = INF;
        cnt = 0;
        solve(n);
    }
    return 0;
}

// 上述过程之所以需要搜索所有情况是因为我们无法确定最短的合法序列长度是多少
// 所以还有一种思路是枚举最短的合法序列长度，在规定的长度内判断是否存在解
// 迭代加深在本题中并没有很好的体现，因为迭代加深似乎是应对一些特殊情况所指定的一种搜索顺序，但是在本题中枚举最短合法序列长度似乎属于正常解题思路
// 不过本题是符合迭代加深的特征的，因为目标是搜索合法序列，一些合法序列的层数确实较深，因此首先规定搜索层数
// 但是规定搜索层数这个操作如果不看为迭代加深的过程，是可以作为另一种解题思路的，所以这道题就没有明显的体现出迭代加深的独特应用来
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

int n;
int path[N];

// u：当前搜索层数 depth：最大限度搜索层数
bool dfs(int u, int depth) { 
    // 以下两种写法均可以获得正确答案，但是前者在path[u - 1] != n时在depth层未必会return，需要到下一层才会返回，效率会差一些
    // 实际上一个搜索分支在到达depth层时，就已经可以判断该路径是否为合法路径了，直接返回即可
    // if (u > depth) return false;
    // if (path[u - 1] == n) return true;
    if (u == depth) return (path[u - 1] == n);

    bool st[N] = {0};
    for (int i = 0; i < u; ++i)
        for (int j = i; ~j; --j) {
            int s = path[i] + path[j];
            if (s > n || s <= path[u - 1] || st[s]) continue;
            st[s] = true;
            path[u] = s;
            if (dfs(u + 1, depth)) return true;
        }

    return false;
}
void solve(int n) {
    bool st[N] = {0};
    int depth = 1;
    path[0] = 1;

    while (!dfs(1, depth)) ++depth; // 限定最深层数为depth，如果未找到解则加深层次继续搜索

    for (int i = 0; i < depth; ++i) cout << path[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (cin >> n, n) solve(n);
    return 0;
}