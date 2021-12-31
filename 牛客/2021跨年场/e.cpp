#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using LL = long long;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n;
LL q[N], u[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> q[i];
    for (int i = 0; i < n; ++i) cin >> u[i];

    LL res = LONG_MAX;
    for (int i = 0; i < n; ++i)
        res = min(res, u[i] / q[i]);
    
    cout << res << '\n'; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}