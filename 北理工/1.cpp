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

constexpr int INF = 0x3f3f3f3f;

void solve() {
    LL n, m;
    cin >> n >> m;

    LL sum = 1;
    while (n--) {
        LL time;
        cin >> time;
        sum *= time;
    }

    LL tps = 1e7;
    // /会下取整,可能是m点几秒,但是会当作m秒计算,或者在等于m时计算个余数,只有余数为0才OK,否则TLE
    if (((sum + tps - 1) / tps) > m) cout << "TLE\n";
    else cout << "OK\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}