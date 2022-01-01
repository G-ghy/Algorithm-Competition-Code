// 赛后不到1分钟调好，我真的醉了
// 不过存在爆int的问题，没有错误数据我未必看得出
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
using LL = long long;

constexpr int N = 2e5 + 10; // 无向边，忘记开两倍空间了，靠
constexpr int INF = 0x3f3f3f3f;

int n;
unordered_set<int> w;
unordered_set<int> b;
int c[N]; // 0:白色 1:黑色
int cnt[N];
int h[N], e[N], ne[N], idx;
bool st[N];

inline void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
// 黑白染色
inline void bfs(int root) {
    queue<int> q;
    
    q.push(root);
    st[root] = true;

    while (q.size()) {
        int t = q.front(); q.pop();

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (st[j]) continue;
            st[j] = true;

            q.push(j);
            c[j] = c[t] ^ 1;
            ++cnt[t];
            ++cnt[j];
            if (!c[t]) {
                w.insert(t);
                b.insert(j);
            } else {
                w.insert(j);
                b.insert(t);
            }
        }
    }
}
void solve() {
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }

    bfs(1);

    // for (int i = 1; i <= n; ++i) cout << i << ' ' << c[i] << endl;
    LL res = 0; // 极限条件是每一个点可以向N-1个点连边，加起来就爆int了，这被坑了一次
    for (int i = 1; i <= n; ++i)
        if (w.count(i)) res += (int)b.size() - cnt[i];
    
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}