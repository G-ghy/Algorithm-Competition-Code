/**
 * 1. 能够从任意节点取车，还车
 * 2. 一半大小是完美状态
 * 3. 选择最短路，多条最短路选择需要PBMC提供最少自行车的路径，多条PBMC提供自行车相等的路径选择带回PBMC自行车数量最小的路径
 * 4. 边权为路径消耗时间，点权为当前自行车数量
 * 5. 点权最大值为偶数
 * 
 * 链式前向星建图，建立边权 
 * 每个点有个点权 val
 * 维护每个点的路径长度，走到该点需要PBMC提供的自行车数量，走到该点需要带回PBMC自行车的数量
 * 路径长度小的优先，如果路径长度相等，选择需要PBMC提供自行车较少的，需要提供自行车数量相同的，选择需要带回PBMC数量较少的
 * 采用dijkstra实现，先试试floyd能不能行，500的范围感觉可行
 * 
 * 题意理解错误，需要完全模拟人工走这条线路的过程，不走回头路，也就是当前节点多余的自行车只能带到下一个节点而不能拿到上一个节点
 * 例如3 10，需要提供的数量为2，需要带回的数量为5，而非提供的数量为0，带回的数量为3
 * 还是需要维护两个变量，nedd和back
 * 一次求解还是做不到，实际求解涉及到了负数，dijkstra无法处理负权，贪心不成立
 * 
 * 那就只能先跑最短路，找到最短路的长度，然后dfs所有长度等于该长度的路径
 * 从这些路径中找到need和back最优的路径
 * 
 * 超时的原因就在于dfs搜索空间较大
 * 明显的一个剪枝是当当前距离已经大于答案时没有必要继续搜索下去了，加上这个可以解决pat上几个数据点的段错误问题
 * 但是最后一个点还是超时
 * 可以剪枝的地方个人感觉就只剩下在dfs之前判断是否要搜索一个状态那里了，
 * 对于这个，可以在求最短路的时把一个节点a是从哪个点更新过来的进行一个标记，搜索时只搜索那些被标记的点，显然没有被标记的点一定不可能出现在最短路上
 * 为了节省空间，采用二进制进行标记
 * 但是注意，我们只能标记前驱节点，所以dfs时就需要从终点搜向起点
 * 
 * 但是二进制标记后，理论上已经减少了搜索空间，但是最后一个点还是超时了，必须要必须在dijkstra时候保存下前驱节点，在dfs时仅枚举前驱节点
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>; // (点的距离值，点的编号)

constexpr int N = 510, M = N * N;
constexpr int INF = 0x3f3f3f3f;

int capacity, n, ep, m;
int g[N][N];
int minDis, dis[N];
bool st[N];
int val[N];
int minNeed, minBack;
vector<int> path, tmpPath;
vector<vector<int>> prePoint(N);

void dfs(int u, int pre, int d) {
    // 不加这个优化，3，4，7，9个数据点会报段错误，估计是递归层数太深了
    if (d > minDis) return;

    tmpPath.push_back(u);
    if (u == 0) {
        if (d != minDis) {
            tmpPath.pop_back();
            return;
        }
        // 计算当前这条路径的need和back
        int need = 0, back = 0;
        // for (int ver : tmpPath) {
        for (int i = (int)tmpPath.size() - 1; ~i; --i) {
            int ver = tmpPath[i];
            if (val[ver] > 0) {
                if (val[ver] <= back) back -= val[ver];
                else {
                    need += val[ver] - back;
                    back = 0;
                } 
            } else {
                back += -val[ver];
            }
        }
        if (need < minNeed || (need == minNeed && back < minBack)) {
            path = tmpPath;
            minNeed = need;
            minBack = back;
        }
        tmpPath.pop_back();
        return;
    }
    for (int preP : prePoint[u]) dfs(preP, u, d + g[u][preP]);
    // for (int i = 0; i <= n; ++i)
    //     if (g[u][i] != INF && i != u && i != pre) dfs(i, u, d + g[u][i]);
    tmpPath.pop_back();
    return;
}
void dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII>> heap; // 默认小根堆
    heap.emplace(0, 0);

    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int ver = t.second;
        
        if (st[ver]) continue;

        st[ver] = true;
        for (int i = 0; i <= n; ++i)
            if (dis[ver] + g[ver][i] <= dis[i]) {
                if (ver != i) prePoint[i].push_back(ver);
                if (dis[ver] + g[ver][i] < dis[i]) {
                    dis[i] = dis[ver] + g[ver][i];
                    heap.emplace(dis[i], i);
                }
            }
    }
}
void solve() {
    memset(dis, 0x3f, sizeof dis);
    dis[0] = 0;

    cin >> capacity >> n >> ep >> m;
    for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
        g[i][j] = (i == j) ? 0 : INF;
    val[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
        val[i] = (capacity / 2) - val[i]; // 需要额外提供的
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }

    dijkstra();
    minDis = dis[ep];
        
    minNeed = minBack = INF;
    dfs(ep, -1, 0);

    cout << minNeed << ' ';
    // for (int i = 0; i < path.size(); ++i)
    for (int i = (int)path.size() - 1; ~i; --i)
        if (i == (int)path.size() - 1) cout << path[i];
        else cout << "->" << path[i];
    cout << ' ' << minBack << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <cmath>
// #include <vector>
// #include <queue>

// using namespace std;
// using PII = pair<int, int>; // (点的距离值，点的编号)

// constexpr int N = 510, M = N * N;
// constexpr int INF = 0x3f3f3f3f;

// int h[N], e[M], ne[M], w[M], idx;
// int capacity, n, ep, m;
// int minDis, dis[N];
// bool st[N];
// int val[N];
// int minNeed, minBack;
// vector<int> path, tmpPath;
// int prePoint[N];

// void add(int a, int b, int c) {
//     e[idx] = b;
//     ne[idx] = h[a];
//     w[idx] = c;
//     h[a] = idx++;
// }
// // 反向搜，从ep搜向0
// void dfs(int u, int pre, int d) {
//     if (d > minDis) return;

//     tmpPath.push_back(u);
//     if (u == 0) {
//         if (d != minDis) {
//             tmpPath.pop_back();
//             return;
//         }
//         // 计算当前这条路径的need和back
//         int need = 0, back = 0;
//         // 注意是反向搜索，但是计算need和back需要从0点开始的路径，所以枚举路径中的点要反过来
//         for (int i = tmpPath.size() - 1; ~i; --i) {
//             int ver = tmpPath[i];
//             if (val[ver] > 0) {
//                 if (val[ver] <= back) back -= val[ver];
//                 else {
//                     need += val[ver] - back;
//                     back = 0;
//                 } 
//             } else {
//                 back += -val[ver];
//             }
//         }
//         if (need < minNeed || (need == minNeed && back < minBack)) {
//             path = tmpPath;
//             minNeed = need;
//             minBack = back;
//         }
//         tmpPath.pop_back();
//         return;
//     }
//     for (int i = h[u]; ~i; i = ne[i]) {
//         int j = e[i];
//         if (j != pre && ((prePoint[u] >> j) & 1)) dfs(j, u, d + w[i]);
//     }
//     tmpPath.pop_back();
//     return;
// }
// // 正向求，从0点到其它各点的最短路径
// void dijkstra() {
//     priority_queue<PII, vector<PII>, greater<PII>> heap; // 默认小根堆
//     heap.emplace(0, 0);

//     while (heap.size()) {
//         auto t = heap.top(); heap.pop();
//         int ver = t.second;
        
//         if (st[ver]) continue;

//         st[ver] = true;
//         for (int i = h[ver]; ~i; i = ne[i]) {
//             int j = e[i];
//             // 这里需要比较的ver点是所有可能是最短路中的前驱节点，所以在==时也需要进行标记，不能因为没有更新就不标记了
//             if (dis[ver] + w[i] <= dis[j]) {
//                 prePoint[j] |= 1 << ver; // 标记ver是j的一个前驱节点
//                 if (dis[ver] + w[i] < dis[j]) {
//                     dis[j] = dis[ver] + w[i];
//                     heap.emplace(dis[j], j);
//                 }
//             }
//         }
//     }
// }
// void solve() {
//     memset(prePoint, 0, sizeof prePoint);
//     memset(h, -1, sizeof h);
//     memset(dis, 0x3f, sizeof dis);
//     dis[0] = 0;
    
//     cin >> capacity >> n >> ep >> m;
//     val[0] = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> val[i];
//         val[i] = (capacity / 2) - val[i]; // 需要额外提供的
//     }
//     for (int i = 0; i < m; ++i) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         add(a, b, c); add(b, a, c);
//     }

//     dijkstra();
//     minDis = dis[ep];

//     minNeed = minBack = INF;
//     dfs(ep, -1, 0);

//     cout << minNeed << ' ';
//     // 和dfs处的同理
//     // for (int i = 0; i < path.size(); ++i)
//     for (int i = path.size() - 1; ~i; --i)
//         if (i == path.size() - 1) cout << path[i];
//         else cout << "->" << path[i];
//     cout << ' ' << minBack << endl;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     solve();
//     return 0;
// }

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <cmath>

// using namespace std;

// constexpr int N = 510, M = N * N;
// constexpr int INF = 0x3f3f3f3f;

// int capacity, n, ep, m; // capacity：节点最大容量； n：n个点；ep：终点； m：m条边
// int g[N][N];
// int val[N]; // 点权
// int dis[N], sent[N]; // dis:距离；usent:PBMC提供数量(>0:PBMC提供 <0：带回到PBMC)
// bool st[N];
// int prePoint[N]; // 记录路径

// void solve() {
//     memset(dis, 0x3f, sizeof dis);
//     dis[0] = 0;
//     memset(sent, 0x3f, sizeof sent);
//     sent[0] = 0;
//     memset(st, 0, sizeof st);
//     memset(prePoint, -1, sizeof prePoint); // 没有前驱节点

//     for (int i = 0; i <= n; ++i)
//         for (int j = 0; j <= n; ++j)
//             if (i == j) g[i][j] = 0;
//             else g[i][j] = INF;

//     cin >> capacity >> n >> ep >> m;
//     val[0] = 0;
//     for (int i = 1; i <= n; ++i) cin >> val[i];
//     for (int i = 0; i < m; ++i) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         g[a][b] = g[b][a] = c;
//     }

//     for (int i = 0; i <= n; ++i) {
//         int t = -1;
//         for (int j = 0; j <= n; ++j) {
//             if (st[j]) continue;
//             if (t == -1) {
//                 t = j;
//                 continue;
//             }
//             if (dis[j] < dis[t]) t = j;
//             else if (dis[j] == dis[t]) {
//                 // sent[j] < 0 && sent[t] < 0时，找带回数量较少的，即较大值
//                 if (max(sent[j], sent[t]) < 0) t = (sent[j] > sent[t]) ? j : t;
//                 // 都>=0，或一个>0，一个<0，都是找提供数量较少即较小值
//                 else t = (sent[j] < sent[t]) ? j : t;
//             }
//         }

//         st[t] = true;
//         for (int j = 0; j <= n; ++j) {
//             int updateVal = sent[t] + ((capacity / 2) - val[j]);
//             if (dis[j] > dis[t] + g[t][j]) {
//                 dis[j] = dis[t] + g[t][j];
//                 sent[j] = updateVal;
//                 prePoint[j] = t;
//             } else if (dis[j] == dis[t] + g[t][j]) {
//                 if (max(sent[j], updateVal) < 0) {
//                     prePoint[j] = (updateVal > sent[j]) ? t : prePoint[j];
//                     sent[j] = max(sent[j], updateVal);
//                 }
//                 else {
//                     prePoint[j] = (updateVal < sent[j]) ? t : prePoint[j];
//                     sent[j] = min(sent[j], updateVal);
//                 }
//             }
//         }
//     }

//     // for (int i = 0; i <= n; ++i) cout << i << ' ' << prePoint[i] << endl;
//     // cout << endl;
//     // for (int i = 0; i <= n; ++i) cout << i << ' ' << sent[i] << endl;
//     cout << max(sent[n], 0) << ' ';
//     string path = "";
//     int point = ep;
//     while (point != -1) {
//         path += point + '0';
//         point = prePoint[point];
//     }
//     for (int i = (int)path.size() - 1; ~i; --i)
//         if (i == (int)path.size() - 1) cout << path[i];
//         else cout << "->" << path[i];
//     cout << ' ' << -min(sent[n], 0) << endl;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     solve();
//     return 0;
// }