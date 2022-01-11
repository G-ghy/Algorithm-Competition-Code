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

constexpr int N = 5e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = a[i] & 1;
    }

    // 需要快速计算包含奇数个1的区间个数
    // 有考虑分类讨论合法的区间情况，按照最左右区间的数值无非以下4种
    // 1 0
    // 1 1
    // 0 1
    // 0 0
    // 难点在于只要区间内有奇数个1即为合法情况，应该是一种取巧的策略，但是我不知道从哪里入手去想
    // int res = 0, i = 0;
    // while (i < n) {
    //     if (a[i]) {
    //         for (++i; !a[i] && i < n; ++i) ++res;
    //         --i;
    //     }
    //     ++i;
    // }

    // i = n - 1;
    // while (~i) {
    //     if (a[i]) {
    //         for (--i; !a[i] && ~i; --i) ++res;
    //         ++i;
    //     }
    //     --i;
    // }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}