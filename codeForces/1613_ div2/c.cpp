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
using LL = long long;

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

LL n, h;
LL a[N];

bool check(LL mid) {
    LL sum = 0;
    for (int i = 0; i < n - 1; ++i) 
        sum += min(mid, a[i + 1] - a[i]);
    sum += mid;

    return sum >= h;
}
void solve() {
    cin >> n >> h;
    for (int i = 0; i < n; ++i) cin >> a[i];

    LL l = 1, r = 1e18;
    while (l < r) {
        LL mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}