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

using namespace std;

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

int n;
int xl = 0, xr = 0;

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x < 0) ++xl;
        else ++xr;
    }
    
    
    if (xl > 1 && xr > 1) cout << "No\n";
    else cout << "Yes\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}