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

void solve() {
    int x, y;
    cin >> x >> y;
    if (y <= x) cout << 0 << '\n';
    else cout << (y - x) / 10 + ((y - x) % 10 != 0) << '\n';
    // 2 1最终答案为1，负数除法一定要小心
    // cout << max(0, (y - x) / 10 + ((y - x) % 10 != 0)) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}