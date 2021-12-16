/**
 * 多叉树
 * 层序遍历统计每一层叶子节点个数
 * 按层输出
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 150, M = N * N / 2;

int n, m;
int h[N], e[M], ne[M], idx;
queue<int> q;
int res[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);

    int a, k, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> b;
            add(a, b);
        }
    }

    int inx = 0;
    q.push(1);
    while (q.size())
    {
        int num = q.size();
        while (num --)
        {
            int t = q.front(); q.pop();
            if (h[t] == -1) ++res[inx];
            for (int i = h[t]; ~i; i = ne[i]) q.push(e[i]);
        }
        ++inx;
    }
    
    for (int i = 0; i < inx; ++i)
        if (i == inx - 1) cout << res[i] << endl;
        else cout << res[i] << ' ';

    return 0;
}