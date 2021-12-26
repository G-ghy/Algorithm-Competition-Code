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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int f[18][N];

inline void init() {
    for (int i = 0; i < 18; ++i)
        for (int j = 1; j < N; ++j)
            f[i][j] = f[i][j - 1] + ((j >> i) & 1 ? 0 : 1);
}
void solve() {
    int l, r;
    cin >> l >> r;

    int minn = INF;
    for (int i = 0; i < 18; ++i)
        minn = min(minn, f[i][r] - f[i][l - 1]);
    
    cout << minn << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}