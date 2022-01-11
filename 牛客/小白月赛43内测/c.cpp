#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

constexpr int N = 10;
constexpr int INF = 0x3f3f3f3f;

int n;
int woodLen[N];
double res;
// bool st[N];
double l[3];

inline bool check(double l[]) {
    return (l[0] + l[1] > l[2]) && (l[0] + l[2] > l[1]) && (l[1] + l[2] > l[0]);
}
// 枚举每一个木棒放入哪一条边中
void dfs(int u) {
    if (u == n) {
        if (check(l)) {
            double p = (l[0] + l[1] + l[2]) / 2;
            res = max(res, sqrt(p * (p - l[0]) * (p - l[1]) * (p - l[2])));
        }
        return;
    }

    for (int i = 0; i < 3; ++i) {
        // 木棒u不放入任何一条边内
        dfs(u + 1);
        
        // 木棒u放入l[i]的边中
        l[i] += woodLen[u];
        dfs(u + 1);
        l[i] -= woodLen[u];
    }
    // for (int i = 0; i < n; ++i) {
    //     if (st[i]) continue;
        
    //     st[i] = true;
    //     l[u] += woodLen[i];
    //     dfs(u + 1); // 将木棒i放在u这条边上
    //     l[u] -= woodLen[i];
    //     st[i] = false;

    //     dfs(u + 1); // 不把木棒放在u这条边上
    // }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> woodLen[i];
    
    res = -INF;
    dfs(0);

    if (res != -INF) printf("%.1lf\n", res);
    else printf("-1\n");
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    solve();
    return 0;
}