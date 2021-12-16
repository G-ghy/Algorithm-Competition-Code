// 建图，修改时仅修改根节点的标记，查询时更新整颗树
// 就感觉是道裸题，而且总感觉在哪里见过，但是就是想不出来怎么搞，我猜测需要用数据结构维护，但是没想到这是个什么什么东西

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
using LL = long long;

constexpr int N = 2e5 + 10, M = N;

int n;
int h[N], e[M], ne[M], idx;
LL v[N], st[N], maxv[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
LL dfs(int x) // 搜索以x为根节点的树中的最高性价比，同时维护各节点值
{
    v[x] += st[x];
    LL maxx = v[x];
    for (int i = h[x]; ~i; i = ne[i])
    {
        int j = e[i];
        st[j] += st[x];
        maxx = max(maxx, dfs(j));
    }
    st[x] = 0;
    maxv[x] = maxx;
    return maxv[x];
}
void solve()
{
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int q;
    int op, preop = 0, x, y;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d", &x, &y);
            st[x] += y;
        }
        else
        {
            scanf("%d", &x);
            if (preop == 1)
            {
                dfs(1);
                printf("%lld\n", maxv[x]);
            }
            else printf("%lld\n", maxv[x]);
        }
        preop = op;
    }
}
int main()
{
    solve();

    return 0;
}