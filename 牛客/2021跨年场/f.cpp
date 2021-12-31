// 需要平方求和公式
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

// constexpr int N = 1e9 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = 1000000007;

int ni;

inline int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }

    return res;
}
inline int get(int x) {
    return 1ll * x * (x + 1) % MOD * (2 * x + 1) % MOD * ni % MOD;
}
void solve() {
    int x;
    cin >> x;
    cout << get(x) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ni = qpow(6, MOD - 2);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}