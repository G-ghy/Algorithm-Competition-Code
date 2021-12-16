/**
 * 1. 最短路径条数
 * 2. 所有最短路中点权和的最大值
 * 
 * 如果仅想获取最短路径长度可以跑最短路算法
 * 但是现在要计算最短路的数量，只能dfs把所有路径搜出来，同时维护最短路径长度，最短路径条数，最短路的点权和最大值
 * 
 * dfs两个参数：当前点，当前路径长度，当前点权和
 * 搜索到终点时，比较当前路径长度和全局最小值
 * 1. 如果当前路径长度 > 全局最小值，那么不做任何处理直接return
 * 2. 如果当前路径长度 = 全局最小值，那么最短路径条数的计数器+1，维护最大点权和
 * 3. 如果当前路径长度 < 全局最小值，全局最小值更新为当前路径长度，计数器恢复1，最大点权和更新为当前点权和
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = N * N / 2;
const int INF = 0x3f3f3f3f;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int v[N];
int startP, endP;
int minPath, maxVSum, minPathCnt;
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u, int pathLen, int pathVal)
{
    if (u == endP)
    {
        if (pathLen > minPath) return ;
        if (pathLen == minPath)
        {
            ++minPathCnt;
            maxVSum = max(maxVSum, pathVal);
            return ;
        }
        minPath = pathLen;
        minPathCnt = 1;
        maxVSum = pathVal;
        return ;
    }
    st[u] = true;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (st[j]) continue;
        dfs(j, pathLen + w[i], pathVal + v[j]);
    }
    st[u] = false;
}
int main()
{
    memset(h, -1, sizeof h);
    minPath = INF, maxVSum = minPathCnt = 0;
    cin >> n >> m >> startP >> endP;
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs(startP, 0, v[startP]);

    cout << minPathCnt << ' ' << maxVSum << endl;

    return 0;
}
