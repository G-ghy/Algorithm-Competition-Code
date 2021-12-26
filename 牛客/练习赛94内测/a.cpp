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

constexpr int N = 35;
constexpr int INF = 0x3f3f3f3f;

int bin[N], idx;

inline void getBin(int x) {
    while (x) {
        bin[idx++] = x & 1;
        x >>= 1;
    }
}
void solve() {
    int d;
    cin >> d;

    getBin(d);

    int a, b, c;
    a = b = c = 0;
    bool first = true;
    for (int i = 0; i < idx; ++i)
        if (bin[i]) {
            a |= 1 << i;
            if (first) {
                b |= 1 << i;
                first = false;
            } else c |= 1 << i;
        }

    if (a > 0 && b > 0 && c > 0) cout << a << ' ' << b << ' ' << c << endl;
    else cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}