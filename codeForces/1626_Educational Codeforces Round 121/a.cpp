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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

int cnt[30];

void solve() {
    memset(cnt, 0, sizeof cnt);

    string str;
    cin >> str;

    for (int i = 0; i < (int)str.size(); ++i)
        ++cnt[str[i] - 'a'];

    string res = "";
    for (int i = 0; i < 26; ++i)
        if (cnt[i] >= 2)
            for (int j = 0; j < cnt[i]; ++j) res += i + 'a';

    for (int i = 0; i < 26; ++i)
        if (cnt[i] == 1)
            res += i + 'a';
    
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}