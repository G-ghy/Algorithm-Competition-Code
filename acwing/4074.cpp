#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

constexpr int N = 410, INF = 0x3f3f3f3f;

int n, m;
int rg[N][N], hg[N][N]; //rg: raliway graph, hg: highway graph

void floyd(int g[][N]) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
void solve() {
    memset(rg, 0x3f, sizeof rg); // 求最短路初始化为最大值
    memset(hg, 0x3f, sizeof hg);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rg[x][y] = rg[y][x] = 1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i !=j && rg[i][j] != 1)
                hg[i][j] = hg[j][i] = 1;

    floyd(rg);
    floyd(hg);

    int res = max(rg[1][n], hg[1][n]);
    if (res == INF) res = -1;

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

/**
 * 主要冲突不知道怎么解决
 * 两个图跑最短路，遇到冲突怎么搞
 * 有个想法是如果发生冲突让当前时间更长的先走
 * 
 * 首先,一定要读懂题目中的这句话: "对于每对不同的城市 x,y，当且仅当它们之间没有铁路时，它们之间会存在一条双向公路。"
 * 这句话所谓的两点之间,是指直接相连,通过中间点相连不算
 * 根据这点可以得到一个非常重要的性质:从起到到终点,一定存在着一个长度为1的铁路或者公路
 * 也就是火车或者汽车一定有一者可以以1的时间从起点到达终点且不需要经过中间任意点
 * 即我们只需要保证另一台车以最短路到达即可
 * 即我们只需要分别对火车和汽车做最短路,两者取max即为答案
 * 
 * 冲突根本就是迷惑人的,因为根本就不会产生冲突
 * 不能因为题目说了你就认为有,然后陷入到如何解决冲突的坑里面
 * 就好比一些数学题目的中间过程可能出现非常复杂的内容,但是最后却抵消掉了,如果一直纠结如何解决这些复杂内容,自然无法解决题目了
 * 不要因为题目中说到了冲突,你就去想如果冲突产生了怎么解决,实际情况是根本就不会产生冲突
 */