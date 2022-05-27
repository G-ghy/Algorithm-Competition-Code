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

constexpr int N = 55;
constexpr int INF = 0x3f3f3f3f;

int n;
int a[N];

bool check(int eps) {
    int bl = -1;
    for (int i = 0; i < n; ++i) {
        int l = a[i] - eps;
        int r = a[i] + eps;

        if (r < bl) return false;

        if (l < bl) ++bl;
        else bl = l + 1;
    }
    return true;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 1, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}