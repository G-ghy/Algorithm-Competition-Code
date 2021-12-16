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

inline bool check1(LL x, LL y, LL a, LL b, LL n) {
    if (y != x - a + b) return false;
    return ((x >= a + max(1 - a, 1 - b)) && (x <= a + min(n - a, n - b)));
}
inline bool check2(LL x, LL y, LL a, LL b, LL n) {
    if (y != -x + a + b) return false;
    return ((x >= a + max(1 - a, b - n)) && (x <= a + min(n - a, b - 1)));
}
void solve() {
    LL n, a, b;
    LL p, q, r, s;
    
    cin >> n >> a >> b;
    cin >> p >> q >> r >> s;
    
    for (LL i = p; i <= q; ++i) {
        for (LL j = r; j <= s; ++j)
            if (check1(i, j, a, b, n) || check2(i, j, a, b, n)) cout << "#";
            else cout << ".";
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}