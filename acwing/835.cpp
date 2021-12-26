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

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int idx;
int son[N][26];
int cnt[N];

inline void insert(string &str) {
    int p = 0;
    for (char c : str) {
        int u = c - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    ++cnt[p];
}
inline int query(string &str) {
    int p = 0;
    for (char c : str) {
        int u = c - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string op, str;
        cin >> op >> str;
        if (op == "I") insert(str);
        else cout << query(str) << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}