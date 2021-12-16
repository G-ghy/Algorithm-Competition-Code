/**
 * 二维矩阵中
 * .表示可走
 * #表示不可走
 * G表示好人，B表示坏人
 * 
 * 通过修改.变为#是否可以让所有G到达终点，所有B无法到达终点
 * 
 * 注：
 * 1. G和B的初始化位置不能更改，即一定可以走
 * 2. G和B均可是多个
 *
 * 设想：如果G到终点和B到终点的路径存在非公共点，那么一定可以保证让G到终点而B无法到达终点
 * 路径指除起点外的所有点
 * 目前能看出的问题是一个点到终点的路径有多条，路径是否存在非公共点的路径很难指明
 * 
 * 预感是寻找无解的强性质，但是图上的情况过于复杂，很难通过一些数据来推断出是否有解，并且观察到n和m的范围都在50以内，显然是搜索解决
 * 
 * 从贪心的角度来想，G走到终点的路径越短，留给我们对B路径操作的发挥空间越大，B越有可能无法走到终点，即越接近答案
 * 但是我无法证明贪心的正确性，尤其是在复杂的图上
 * 在保证每个G点均存在到达终点的最短路径，
 * 并且把除了从终点到达G点的最短路径外的所有**可标记点**修改为墙，从终点如果无法搜索到B证明有解，反之无解
 * 这种思路所有样例均可通过
 * 
 * bfs需要一个队列，bfs过程中需要维护当前路径以便在找到G点时对路径以外的点进行标记，bfs只能通过给定下一个点当前点信息，在找到G点时反向找回来，需要使用PII pre[][]保存一个点的前一个点
 * bool st[][] 标记是否为终点到G点的路径，为false且不为'B'的点全部修改为'-'
 * 建图时需要保存所有G点的位置，在bfs之后通过st判定是否所有G点均能够到达终点，如果不是则无解(可以借助st实现，G点的st初始值为false，在从终点找到时会被标记为true)，最后只要遍历一遍整张图，如果某个点是G点且st为false说明无解
 * 在将图修改后，从终点搜B点需要使用dfs，如果找到B点说明无解，反之有解
 * 
 * 1. 如果不存在G点，那么答案一定是"Yes"，无论B点是否存在，只需要把终点改为#就一定可以满足题意
 * 2. 如果存在G点
 *    从终点出发开始bfs
 *    1. 如果存在不可达的G点，那么答案为"No"
 *    2. 如果所有G点均可达，那么
 *       1. 如果将所有除到达G点的最短路径外的所有可修改点修改为#后不存在可达的B点，那么答案为“Yes”
 *       2. 如果修改后存在可达的B点，那么答案为“No”
 * 
 * 通过下面这组数据可以找到错误原因
 * 1
 * 3 4
 * G#B.
 * .G..
 * GGG.
 * 问题出在(2，2)的G点，终点到它的最短路径有两条
 * 一条是(3,4) -> (2,4) -> (2,3) -> (2,2)
 * 另一条是(3,4) -> (3,3) -> (3,2) -> (2,2)
 * 由于偏移数组定的是先向上走，因此实际找到的最短路径是上面那一条
 * 所以在修改除了终点到G点的路径上的可修改点为#时，就不会把B下面的位置修改为B，
 * 因此从终点可以走到B点，所以答案为No
 * 但实际上可以将B点下方的点进行修改，而(2，2)的G点可以采取第2条路径
 * 因此正确答案为Yes
 * 
 * 其实在想到这种做法之后我并没有对其进行严密的证明，对其正确性也是半信半疑
 * 现在看来，这种想法是错误的，但是这种问题如果不是想到特定的样例很难想到
 * 
 * 我的想法的入手点是放在了G点上，而正解的入手点是放在B点上的
 * 我考虑的是如果让G点走出去，正解考虑的是如果不让B点走出去
 * 我考虑的是让G点走最短路出去，这样可以给不让B走出去留下尽可能多的可能。我没有考虑到最短路存在多条的问题
 * 正解考虑的是把B点周围的.全部修改为#，这样既可以保证B点无法走出去，同时又能够给让G点留下更多的路，更容易走出去
 * 其实我的思考方向是正确的，就是如果最大限度做到利他，错在思考对象出现了问题
 * 
 * 想要确保B点无法走到终点，最少也要将与它相邻的.改变为#
 * 上一步完成之后，不能保证B点一定无法达到终点，因为B点周围如果有G点，且该G点可以达到终点，那么B点一定可以达到终点(这是容易忽视的地方)
 * 建图时统计G点数目gcnt
 * 1. 先将B点周围相邻的.改为#
 * 2. 从终点开始bfs，统计可以到达的G点数目arrive_gcnt，同时对可达的G点进行标记arrive_st[][]
 *    如果arrive_gcnt != gcnt，说明存在不可到达终点的G点，无解
 *    如果等于，则进行下一步
 * 3. 遍历所有B点，查看其周围相邻点中是否有可达终点的G点
 *    如果存在，则无法满足该B点无法到达终点，无解
 *    如果所有B点周围均不存在，则有解
 */ 

// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <cstring>

// using namespace std;

// using PII = pair<int, int> ;

// const int N = 55;

// int n, m;
// char g[N][N];
// bool path[N][N];
// bool st[N][N];
// PII pre[N][N];
// queue<PII> q;
// int dx[] = {-1, 0, 1, 0};
// int dy[] = {0, 1, 0, -1};

// void sign(int x, int y)
// {
//     PII p = {x, y}, end = {n, m};
//     while (p != end) 
//     {
//         path[x][y] = true;
//         p = pre[x][y];
//         x = p.first, y = p.second;
//     }
//     path[x][y] = true;
// }
// int main()
// {
//     int T;
//     cin >> T;
//     while (T --)
//     {
//         memset(st, 0, sizeof st);
//         memset(path, 0, sizeof path);
//         while (!q.empty()) q.pop(); // 第二个bfs不能保证结束时q为空

//         cin >> n >> m;
//         for (int i = 1; i <= n; ++i)
//             for (int j = 1; j <= m; ++j)
//                 cin >> g[i][j];

//         st[n][m] = true;
//         q.push({n, m});
//         while (q.size())
//         {
//             auto t = q.front(); q.pop();
//             int x = t.first, y = t.second;

//             if (g[x][y] == 'G') sign(x, y);
            
//             for (int i = 0; i < 4; ++i)
//             {
//                 int a = x + dx[i], b = y + dy[i];
//                 if (a <= 0 || a > n || b <= 0 || b > m) continue;
//                 if (st[a][b] || g[a][b] == '#') continue;

//                 st[a][b] = true;
//                 q.push({a, b});
//                 pre[a][b] = {x, y};
//             }
//         }

//         for (int i = 1; i <= n; ++i)
//             for (int j = 1; j <= m; ++j)
//                 if (!path[i][j])
//                 {
//                     if (g[i][j] == 'G' || g[i][j] == 'B') continue;
//                     g[i][j] = '#';
//                 }

//         // cout << endl;
//         // for (int i = 1; i <= n; ++i)
//         // {
//         //     for (int j = 1; j <= m; ++j)
//         //         cout << g[i][j];
//         //     cout << endl;
//         // }
//         bool flag = true;
//         for (int i = 1; i <= n; ++i)
//             for (int j = 1; j <= m; ++j)
//                 if (g[i][j] == 'G')
//                 {
//                     flag = false;
//                     break;
//                 }
//         if (flag) // 不存在G点
//         {
//             cout << "Yes" << endl;
//             continue;
//         }

//         flag = true;
//         for (int i = 1; i <= n; ++i)
//             for (int j = 1; j <= m; ++j)
//                 if (g[i][j] == 'G' && !path[i][j]) // 存在搜不到的G点
//                 {
//                     flag = false;
//                     break;
//                 }


//         if (flag) // 所有G点均可达
//         {
//             memset(st, 0, sizeof st);
//             st[n][m] = true;
//             q.push({n, m});
//             while (q.size())
//             {
//                 auto t = q.front(); q.pop();
//                 int x = t.first, y = t.second;

//                 if (g[x][y] == 'B')
//                 {
//                     flag = false;
//                     break;
//                 }
//                 for (int i = 0; i < 4; ++i)
//                 {
//                     int a = x + dx[i], b = y + dy[i];
//                     if (a <= 0 || a > n || b <= 0 || b > m) continue;
//                     if (st[a][b] || g[a][b] == '#') continue;
                    
//                     st[a][b] = true;
//                     q.push({a, b});
//                 }
//             }
//         }
//         if (flag) cout << "Yes" << endl;
//         else cout << "No" << endl;
//     }

//     return 0;
// }
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using PII = pair<int, int>;

const int N = 55;

int n, m;
int gcnt, arrive_gcnt;
bool arrive_st[N][N];
char g[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int u, int v)
{
    queue<PII> q;
    bool st[N][N];
    memset(st, 0, sizeof st);
    memset(arrive_st, 0, sizeof arrive_st);

    if (g[u][v] == '#') return ;
    st[u][v] = true;
    q.push({u, v});
    while (q.size())
    {
        auto t = q.front(); q.pop();
        int x = t.first, y = t.second;

        if (g[x][y] == 'G') 
        {
            ++arrive_gcnt;
            arrive_st[x][y] == true;
        }

        for (int i = 0; i < 4; ++i)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a <= 0 || a > n || b <= 0 || b > m) continue;
            if (st[a][b] || g[a][b] == '#') continue;

            st[a][b] = true;
            q.push({a, b});
        }
    }
     
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        gcnt = arrive_gcnt = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                cin >> g[i][j];
                if (g[i][j] == 'G') ++gcnt;
            }
        
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (g[i][j] == 'B')
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        int a = i + dx[k], b = j + dy[k];
                        if (a <= 0 || a > n || b <= 0 || b > m) continue;
                        if (g[a][b] == 'G' || g[a][b] == 'B') continue;
                        g[a][b] = '#';
                    }
                }

        bfs(n, m);

        bool flag = (arrive_gcnt == gcnt);

        if (flag) // arrive_gcnt == gcnt
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= m; ++j)
                    if (g[i][j] == 'B')
                    {
                        for (int k = 0; k < 4; ++k)
                        {
                            int a = i + dx[k], b = j + dy[k];
                            if (a <= 0 || a > n || b <= 0 || b > m) continue;
                            if (g[a][b] == 'G' && !arrive_st[a][b])
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) break;
                    }
                if (!flag) break;
            }
        }

        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}