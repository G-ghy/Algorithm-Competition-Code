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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, m, k;
int f[N];

void solve() {
    cin >> n >> m >> k;
    while (n--) {
        int t, c;
        cin >> t >> c;
        
        if (t - k >= 1) {
            ++f[max(1, t - k - (c - 1))];
            --f[t - k + 1];
        }
    }

    for (int i = 1; i < N; ++i)
        f[i] += f[i - 1];

    while (m--) {
        int q;
        cin >> q;
        cout << f[q] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
// t k
// [t + k, t + k + (k - 1)]

// t + c = e
// t = e - c

// t + c + (c - 1) = e
// t = e - (c - 1) - c

// [e - (c - 1) - c, e - c]

// 11 24
// [-36, -13]

// [11, 21]
// [q + k, q + k + (k - 1)]