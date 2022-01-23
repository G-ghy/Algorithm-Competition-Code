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

constexpr int N = 200010;
constexpr int INF = 0x3f3f3f3f;

int n;
int a[N];
stack<int> sta;

inline void clear(stack<int> &sta) {
    while (sta.size()) sta.pop();
}
// 只能向一个方向走，而且一旦前面的比当前的高那么前面的所有都没有用了，还要统计个数，不难想到单调栈
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = a[n + 1] = 1e9 + 7;

    // 第一次单调栈的实现细节错误，第2次完全忽略了还有inf的情况，第3次没考虑对什么时候inf
    bool flag = false;
    for (int i = 1; i < n; ++i)
        if (a[i] == a[i + 1]) {
            flag = true;
            break;
        }
    
    if (flag) {
        cout << "inf\n";
        return;
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (sta.size() && sta.top() > a[i]) clear(sta);
        sta.push(a[i]);
        res = max(res, (int)sta.size());
    }
    clear(sta);
    for (int i = n; i >= 1; --i) {
        if (sta.size() && sta.top() > a[i]) clear(sta);
        sta.push(a[i]);
        res = max(res, (int)sta.size());
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}