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

LL p, q;
LL a1, a2, b;

void solve() {
    cin >> p >> q;
    LL t = p * p - 4 * q * q;
    if (t < 0) {
        cout << "0 0" << endl;
        return;
    } else if (!t) {
        if (p & 1) {
            cout << "0 0" << endl;
            return;
        }
        a1 = p >> 1;
        if (q % a1 != 0) { 
            cout << "0 0" << endl;
            return;
        }
        b = q / a1;
        cout << a1 << ' ' << b << endl;
    } else {
        bool flag = false;
        if ((p + sqrt(t)))
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}