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

constexpr int N = 110, M = N * N / 2;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) p[i] = i;

    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        
        int pa = find(a), pb = find(b);
        if (pa == pb) ++cnt;
        else p[pa] = pb;
    }

    bool flag = (cnt == 1);
    if (flag) {
        cnt = 0;
        for (int i = 1; i <= n; ++i) find(i);
        for (int i = 1; i <= n; ++i)
            if (p[i] == i) ++cnt;
        flag = (cnt == 1);
    }

    cout << (flag ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}