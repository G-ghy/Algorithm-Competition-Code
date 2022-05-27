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
using PII = pair<int, int>;

constexpr int N = 2e5 + 10, M = 2 * N;
constexpr int INF = 0x3f3f3f3f;

int n;
int h[N], e[M], ne[M], w[M], idx;
queue<int> q;
int v[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
void bfs(int u) {
    
}
void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b, 0);
        add(b, a, 1);
    }

    for (int i = 1; i <= n; ++i) add(0, i);

    bfs(0);

    int minn = INF;
    vector<int> res;
    for (int i = 1; i <= n; ++i)
        if (v[i] < minn) {
            res.clear();
            res.push_back(i);
            minn = v[i];
        } else if (v[i] == minn) {
            res.push_back(i);
        }

    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (int v : res) cout << v << ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}