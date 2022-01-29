#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

constexpr int N = 10010;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int p[N], d[N];
unordered_map<int, int> s;

// 离散化
inline int get(int x) {
    if (!s.count(x)) s[x] = ++n;
    return s[x];
}
int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] = (d[x] + d[p[x]]) % 2;
        p[x] = root;
    }
    return p[x];
}
void solve() {
    cin >> n >> m;
    n = 0; // 离散化仍然使用n作为点数,所以此处初始为0

    for (int i = 0; i < N; ++i) p[i] = i;

    int res = m; // 若不存在非法条件则答案为m
    for (int i = 1; i <= m; ++i) {
        int l, r;
        string type;
        cin >> l >> r >> type;
        l = get(l - 1), r = get(r);
        int pl = find(l), pr = find(r);

        if (type == "even") { // 相同奇偶性，如果并查集中pl != pr则一定不会发生矛盾，添加相同关系即可；若pl == pr, 需要查看并查集中保存的关系是否与此时给定的条件矛盾
            if (pl != pr) {
                p[pl] = pr;
                d[pl] = (d[r] - d[l] + 2) % 2; // 两元素具有相同奇偶性时的合并方法
            } else {
                if ((d[r] - d[l] + 2) % 2 == 1) { // 并查集中维护的是l和r具有不同奇偶性，与此时条件矛盾
                    res = i - 1;
                    break;
                }
            }
        } else { // 不同奇偶性
            if (pl != pr) {
                p[pl] = pr;
                d[pl] = (d[r] - d[l] + 1 + 2) % 2; // 两元素具有不同奇偶性时的合并方法
            } else {
                if ((d[r] - d[l] + 2) % 2 == 0) { // 并查集中维护的是l和r具有不同奇偶性，与此时条件矛盾
                    res = i - 1;
                    break;
                }
            }
        }
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}