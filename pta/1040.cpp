// O(n^2)
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

void solve() {
    string str;
    getline(cin, str);

    int res = -INF;
    for (int i = 0; i < (int)str.size(); ++i)
        for (int len  = max(1, res); len <= (int)str.size() - i; ++len) {
            string substr = str.substr(i, len);
            string resubstr = substr;
            reverse(resubstr.begin(), resubstr.end());
            if (substr == resubstr) res = max(res, (int)substr.size());
        }

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}