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
using LL = long long;

constexpr int N = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, t;
int a[N];
LL sum = 0;

LL getSum(int l, int r, int high) {
    if (l == r) {
        sum += a[l];
        return a[l];
    }
    
    int mid = l + r >> 1;
    LL left = getSum(l, mid, high >> 1);
    LL right = getSum(mid + 1, r, high >> 1);
    
    sum += (left + right) * 2;
    return (left + right) * 2;
}
void solve() {
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    getSum(1, n, n);
    
    int high = 0;
    while (1 << high != n) ++high;
    ++high;

    while (t--) {
        int l, r, k;
        cin >> l >> r >> k;
        sum += (1ll * (1ll << high) - 1) * k * (r - l + 1);
        cout << sum << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}