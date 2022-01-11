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

constexpr int N = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;

int h[N];

inline int qSort(int h[], int l, int r, int k) {
    if (l >= r) return h[l];

    int x = h[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        while (h[++i] < x);
        while (h[--j] > x);
        if (i < j) swap(h[i], h[j]);
    }

    int sl = j - l + 1;
    if (k <= sl) return qSort(h, l, j, k);
    return qSort(h, j + 1, r, k - sl);
}
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        ++h[a], --h[b + 1];
    }

    for (int i = 1; i <= n; ++i) h[i] += h[i - 1];

    cout << qSort(h, 1, n, (n + 1) >> 1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}