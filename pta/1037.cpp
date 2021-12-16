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

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int nc, np;
int c[N], p[N];

void solve() {
    cin >> nc;
    for (int i = 0; i < nc; ++i) cin >> c[i];
    cin >> np;
    for (int i = 0; i < np; ++i) cin >> p[i];

    sort(c, c + nc, [](int a, int b) -> bool {return a > b;});
    sort(p, p + np, [](int a, int b) -> bool {return a > b;});
    
    int l, res = 0;
    for (l = 0; l < nc && l < np; ++l)
        if (c[l] * p[l] < 0) break;
        else res += c[l] * p[l];
    
    for (int cr = nc - 1, pr = np - 1; cr >= l && pr >= l; --cr, --pr)
        if (c[cr] * p[pr] < 0) break;
        else res += c[cr] * p[pr];
    
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}