/**
 * 对于给定的一张无向图，若去掉某点后，询问使其余所有点连通的最少加边数
 * 有一种想法是：最少加边数 == 去掉某点后图上连通块数 - 1
 * 有考虑并查集，但是并查集对于删点这个操作逻辑上并不好去实现，所以还是每次跑便dfs找一下连通块数
 * 
 * K次查询，最多1e3，每次dfs相当于遍历一遍所有点，1e3，这么分析这应当是不会超时的，但是此前做过一道题，需要真的去删边，否则会超时
 * 
 * 另外使用一个数组标记每条边是不是还在
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 1e3 + 10, M = N * N; // 双向边注意M的大小

int n, m, k;
int h[N], e[M], ne[M], idx;
bool st_edge[M], st_point[N]; // 某天边是否失效
int cnt; // 连通块数量


inline void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
inline void del(int x) {
    for (int i = h[x]; ~i; i = ne[i]) {
        st_edge[i] = st_edge[i ^ 1] = true; // 双向都需要标记，因为加边时同一条边的两个方式是同时添加的，因此两个编号符合^1的关系
    }
}
void dfs(int x) {
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st_point[j]) {
            st_point[j] = true;
            dfs(j);
        }
    }
}
void solve() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }

    while (k--) {
        int x;
        scanf("%d", &x);
        cnt = 0;
        memset(st_edge, 0, sizeof st_edge);
        memset(st_point, 0, sizeof st_point);


        del(x);
        
        st_point[x] = true;
        for (int i = 1; i <= n; ++i)
            if (!st_point[i]) {
                ++cnt;
                st_point[i] = true;
                dfs(i);
            }
        
        printf("%d\n", cnt - 1);
    }
}
int main() {
    solve();
    return 0;
}