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

vector<int> a;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    int res = 0;
    while (k--) {
        auto p = upper_bound(a.begin(), a.end(), a[0]);
        if (p == a.end()) {
            res += a[0] / a[1];
            a.erase(a.begin() + 1);
            a.erase(a.begin());
        } else {
            res += a[0] / (*p);
            a.erase(p);
            a.erase(a.begin());
        }
    }

    for (int i : a) res += i;
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}