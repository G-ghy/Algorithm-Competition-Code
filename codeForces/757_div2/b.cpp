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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n;
pair<int, int> a[N]; // first：次数，second：序号
int x[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1, [](pair<int, int> &a, pair<int, int> &b) -> bool {return a.first > b.first;});

    x[0] = 0;
    int pos = 1;
    LL res = 0;
    for (int i = 1; i <= n; ++i) {
        x[a[i].second] = pos;
        res += 2ll * abs(pos) * a[i].first;
        if (pos > 0) pos = -pos;
        else pos = -pos + 1;
    }

    cout << res << endl;
    for (int i = 0; i <= n; ++i) cout << x[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}