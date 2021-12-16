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

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

int n, l, r, k;
int a[N];

void solve() {
    cin >> n >> l >> r >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] < l) continue;
        else if (a[i] > r) break;
        else {
            if (k - a[i] < 0) break;
            k -= a[i];
            ++cnt;
        }
    cout << cnt << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}