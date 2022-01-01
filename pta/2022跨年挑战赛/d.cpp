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

int n;
string rule[N];
string result[5] = {"YiDengJiang!!!", "ErDengJiang", "SanDengJiang", "SiDengJiang", "WuDengJiang"};

inline int getRes(string &l, string &rule) {
    int n = rule.size();

    for (int i = n - 1; ~i; --i)
        if (l[i] != rule[i]) return i + 1;
    
    return 0;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> rule[i];

    int res = INF;
    for (int i = 0; i < 3; ++i) {
        string l;

        cin >> l;
        for (int j = 0; j < n; ++j) {
            res = min(res, getRes(l, rule[j]));
            if (res == 1) break;
        }

        if (res == 1) break;
    }

    cout << result[res] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}