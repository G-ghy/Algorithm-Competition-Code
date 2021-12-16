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

constexpr int N = 1010;
constexpr int INF = 0x3f3f3f3f;

LL f[N];

inline LL gcd(LL a, LL b) {
    LL r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> f[i];
    
    LL o = 0, e = 0; // o奇数位，e偶数位
    for (int i = 1; i <= n; ++i)
        if (i & 1) o = gcd(o, f[i]);
        else e = gcd(e, f[i]);

    bool flag = true;
    for (int i = 1; i <= n; ++i)
        if (i & 1 && f[i] % e == 0) {
            flag = false;
            break;
        }
    
    if (flag) {
        cout << e << endl;
        return;
    }

    flag = true;
    for (int i = 1; i <= n; ++i)
        if (!(i & 1) && f[i] % o == 0) {
            flag = false;
            break;
        }
    if (flag) cout << o << endl;
    else cout << 0 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}