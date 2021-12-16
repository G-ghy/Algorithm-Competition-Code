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

constexpr int N = 10;
constexpr int INF = 0x3f3f3f3f;

int f[N];

void solve() {
    int n = 7;
    int a, b, c;

    for (int i = 1; i <= n; ++i) cin >> f[i];
    
    a = f[n] - f[n - 1];
    c = f[n - 2] - a;
    if (f[n - 3] == c) b = f[n - 4] - a;
    else b = f[n - 3] - a;

    cout << a << ' ' << b << ' ' << c << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}