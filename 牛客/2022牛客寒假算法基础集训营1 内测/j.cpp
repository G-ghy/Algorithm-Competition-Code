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
#include <fstream>

using namespace std;
using LL = long long;

constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = 1000000007;

inline LL qpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
inline LL gcd(LL a, LL b) {
    LL r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
inline LL lcm(LL a, LL b) {
    LL ni = qpow(gcd(a, b), MOD - 2);
    return (a * b % MOD * ni % MOD);
}
// 判断x是否为质数
inline bool check(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i)
        if (x % i == 0) return false;
    return true;
}
void solve() {
    LL l, r;
    cin >> l >> r;

    LL res = -1;
    for (LL i = l; i <= r; ++i)
        if (!check(i)) {
            if (res == -1) {
                res = i;
                continue;
            }
            res = lcm(res, i);
        }
    
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}