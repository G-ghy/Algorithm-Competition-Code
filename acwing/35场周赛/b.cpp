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
using LL = long long;

constexpr int N = 5;
constexpr LL INF = 1000000000000; // long long 下

vector<LL> num;
char op[N];
LL res;

void dfs(int u) {
    if (u == 3) {
        res = min(res, num[0]);
        return;
    }

    for (int i = 0; i < (int)num.size(); ++i)
        for (int j = 0; j < (int)num.size(); ++j) {

            if (j == i) continue;

            LL a = num[i], b = num[j];

            vector<LL> t = num;
            num.clear();
            for (int k = 0; k < t.size(); ++k)
                if (k != i && k != j) num.push_back(t[k]);
            if (op[u] == '*') num.push_back(a * b);
            else num.push_back(a + b);

            dfs(u + 1);

            num = t;
        }
}
void solve() {
    for (int i = 0; i < 4; ++i) {
        LL x;
        cin >> x;
        num.push_back(x);
    }
    for (int i = 0; i < 3; ++i) cin >> op[i];

    res = INF;
    dfs(0);

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}