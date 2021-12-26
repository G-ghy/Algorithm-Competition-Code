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

constexpr int INF = 0x3f3f3f3f;

void solve() {
    int p1, p2, p3, p4;
    int a, b;
    
    cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
    int minn = min(min(min(p1, p2), p3), p4);

    int res;
    if (minn <= b) res = max(0, minn - a);
    else res = b - a + 1;

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}