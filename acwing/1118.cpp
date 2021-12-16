/**
 * 搜索有两种思路
 * 1. 考虑组：考虑每一组中有哪些元素
 * 2. 考虑元素：考虑每一个元素应放置于哪一组中
 * 
 * 最初的想法就是第一种，考虑最终分成多少组，但是涉及到组为空的情况，没想好怎么办
 * 如果是第二种做法，现在已经有了一些组，对于一个元素，我们仅需要考虑是放到已有组中还是新开一个组并把元素放进去
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int N = 15;

int n;
int a[N];
int res;
int gcnt; // 组数
vector<int> g[N];

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
bool check(int u, int ginx) {
    for (int x : g[ginx])
        if (gcd(u, x) != 1) return false;
    return true;
}
void dfs(int u) { // 对于a[u]枚举放在哪一组
    if (u == n) {
        res = min(res, gcnt);
        return;
    }
    // 首先考虑把a[u]放到已有组中
    for (int i = 0; i < gcnt; ++i) {
        if (check(a[u], i)) { // 如果把a[u]放到第i组是合法的，即两两互质
            g[i].push_back(a[u]);
            dfs(u + 1);
            g[i].pop_back();
        }
    }
    // 考虑新开一组放置a[u]
    g[gcnt++].push_back(a[u]);
    dfs(u + 1);
    g[--gcnt].pop_back();
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    gcnt = 0;
    res = N;
    dfs(0); // 枚举所有数，对于一个数考虑其位于每一组中

    cout << res << endl;
}
int main() {
    solve();

    return 0;
}