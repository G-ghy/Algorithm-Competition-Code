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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

void solve() {
    int a, b;
    cin >> a >> b;

    int res_self = max(0, max(a, b));
    int res = (a + b > 0) ? (a + b) : 0;
    cout << res_self << ' ' << res << '\n';

    if (a < 0 && b < 0) cout << "-_-\n";
    else {
        if (res > res_self) cout << "^_^\n";
        else cout << "T_T\n";
        // if (a + b > 0) cout << "^_^\n";
        // else cout << "T_T\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}