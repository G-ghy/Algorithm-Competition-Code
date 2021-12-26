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

constexpr int N = 5e4 + 10;
constexpr int INF = 0x3f3f3f3f;

int n;
LL x;
vector<vector<LL>> bag(N);

LL dfs(int binx, int pinx, LL v) {
    LL res = 0;
    if (v > x) return res;
    if (binx == n) {
        if (v == x) ++res;
        return res;
    }

    LL prev = 0, preres;
    for (int i = pinx; i < bag[binx].size(); ++i) {
        if (bag[binx][i] == prev) res += preres;
        else {
            preres = dfs(binx + 1, 0, v * bag[binx][i]);
            res += preres;
            prev = bag[binx][i];
        }
    }

    return res;
}
void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            int v;
            cin >> v;
            bag[i].push_back(v);
        }
    }
    
    for (int i = 0; i < n; ++i) sort(bag[i].begin(), bag[i].end(), [](int a, int b) -> bool {return a > b;});

    cout << dfs(0, 0, 1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}