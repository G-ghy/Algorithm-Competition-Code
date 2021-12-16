#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
using LL = long long;

void solve() {
    LL u, v, x, y;
    cin >> u >> v;
    x = -u * u;
    y = v * v;
    cout << x << ' ' << y << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}