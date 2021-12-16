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
using PII = pair<int, int>;

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, d;
PII c[N];

void solve() {
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        c[i] = {l, r};
    }

    sort(c, c + n, [](PII &a, PII &b) -> bool {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    int cnt = 1;
    int left = c[0].second, right = c[0].second + d - 1;
    for (int i = 1; i < n; ++i) {
        if (right < c[i].first || left > c[i].second) {
            ++cnt;
            left = c[i].second;
            right = c[i].second + d - 1;
        }
    }
    cout << cnt << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}