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

constexpr int N = 1010;
constexpr int INF = 0x3f3f3f3f;

vector<pair<int, int>> pick;
int in[N];
bool st[N];

void solve() {
    memset(st, false, sizeof st);
    pick.clear();
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; ++j) ++in[j];
        pick.emplace_back(l, r);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (st[i]) continue;

            int l = pick[i].first, r = pick[i].second;
            int pos;
            bool flag = false;
            for (pos = l; pos <= r; ++pos)
                if (in[pos] == 1) {
                    flag = true;
                    break;
                }
            
            if (!flag) continue;
            st[i] = true;
            for (int j = l; j <= r; ++j) --in[j];
            cout << l << ' ' << r << ' ' << pos << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}