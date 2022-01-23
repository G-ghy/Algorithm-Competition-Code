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

int n;
string s, t, basic;

void solve() {
    cin >> s >> n;
    // 外层就已经1e5了，这是不可能降低的，内层至少要控制在logn
    for (int i = 0; i < n; ++i) {
        cin >> t;
        basic = t;
        if (lt < ls) {
            while (t.size() < ls)
                t += basic;
        }
        int cnt = 0;
        for (int j = 0; j < ls; ++j)
            if (s[j] != t[j]) ++cnt;
        cout << cnt << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// 字符串上的技巧可能就多了，以目前我的认知始终逃脱不了遍历检查是否相同的点，时间上过不去