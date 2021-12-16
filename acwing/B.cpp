/**
 * dfs尽可能去搜
 * 如果一个点4个方向都无法走，那么把这个点存下来
 * 最后如果没有找到终点，那么在存下来的点和起点中找到一个距离终点曼哈顿距离最近的点
 * 如果找到了终点，那么答案就是0
 * 
 * 错错错，建立传送阵谁说一定要建立在终点的
 * 
 * 该暴力不暴力，不该暴力只会暴力，服了
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
using PII = pair<int, int>;

constexpr int N = 55, INF = 0x3f3f3f3f;

int n;
char g[N][N];
PII start, endp;
vector<PII> svec, evec;
bool flag;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool st[N][N];

void dfs(PII s, PII e, PII u, vector<PII> &vec)
{
    int x = u.first, y = u.second;
    st[x][y] = true;
    if (u == e)
    {
        flag = true;
        return ;
    }

    for (int i = 0; i < 4; ++i)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a <= 0 || a > n || b <= 0 || b > n) continue;
        if (st[a][b] || g[a][b] == '1') continue;

        dfs(s, e, {a, b}, vec);
        if (flag) return ;
    }
}
inline int get_dis(PII a, PII b)
{
    int x = (a.first - b.first);
    int y = (a.second - b.second);
    return (x * x + y * y);
}
void output()
{
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //         if (st[i][j]) cout << 
    // }
    for (auto i : svec) cout << i.first << ' ' << i.second << endl;
    // for (auto i : evec) cout << i.first << ' ' << i.second << endl;
}
void solve()
{
    cin >> n;
    cin >> start.first >> start.second;
    cin >> endp.first >> endp.second;
    for (int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);

    flag = false;
    memset(st, 0, sizeof st);
    dfs(start, endp, start, svec);
    
    // output();

    if (flag) cout << 0 << endl;
    else
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (st[i][j]) svec.push_back({i, j});

        flag = false;
        memset(st, 0, sizeof st);
        dfs(endp, start, endp, evec);

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (st[i][j]) evec.push_back({i, j});

        int minn = INF;
        for (auto x : svec)
            for (auto y : evec)
                minn = min(minn, get_dis(x, y));
        cout << minn << endl;
    }
}
int main()
{
    solve();

    return 0;
}