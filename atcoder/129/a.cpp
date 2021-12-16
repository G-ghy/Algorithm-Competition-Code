#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;
using LL = long long;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, l, r;
vector<int> vn, vr;

inline LL qpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
inline void change(LL x, vector<int> &v) {
    while (x) {
        v.push_back(x & 1);
        x >>= 1;
    }
}
void solve() {
    cin >> n >> l >> r;
    change(n, vn);
    change(r, vr);

    LL res = 0;
    int ln = vn.size(), lr = vr.size();
    if (n < r) {
        for (int i = 0; i < ln; ++i)
            if (vn[i]) res += qpow(2, i);
    } else {
        for (int i = 0; i < lr; ++i)
            if (vn[i]) res += qpow(2, i);
        
        if (vn[lr - 1]) {
            int cnt = 0;
            for (int i = 0; i < lr; ++i)
                if (vn[i]) ++cnt;
            res += qpow(2, cnt);
        }
    }

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}