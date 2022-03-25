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

constexpr int N = 210;
constexpr int INF = 0x3f3f3f3f;

int n, k;
int a[N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) cin >> a[i];

    int maxx = -INF;
    for (int i = 0; i < k - 1; ++i) maxx = max(maxx, (a[i + 1] - a[i] + 1 + 1) / 2);
    maxx = max(maxx, a[0]);
    maxx = max(maxx, n - a[k - 1] + 1);

    cout << maxx << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}