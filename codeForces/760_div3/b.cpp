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

string str[N];

void solve() {
    int n;
    cin >> n;
    n -= 2;
    for (int i = 0; i < n; ++i) cin >> str[i];

    bool flag = false;
    for (int i = 1; i < n; ++i) {
        string pre = str[i - 1], now = str[i];
        if (pre[(int)pre.size() - 1] != now[0]) {
            flag = true;
            break;
        }
    }

    string pre, now, res = "";
    for (int i = 0; i < n; ++i) {
        now = str[i];
        if (!i || pre[(int)pre.size() - 1] != now[0]) res += now;
        else res += now.substr(1);
        pre = now;
    }

    if (!flag) res += "a";

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