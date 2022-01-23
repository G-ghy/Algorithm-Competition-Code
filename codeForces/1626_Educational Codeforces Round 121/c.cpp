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
using PII = pair<int, int>;
using LL = long long;

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

int n;
int k[N], h[N];

// 如果后一秒的伤害值需要为x
//  x == 1: 前一秒为任意非0值或者前一秒没有施法
//  x != 1: 前一秒必须为x - 1
// 我觉得必须要满足后续的值，假设9秒需要伤害为3，8秒需要伤害为1
// 为了满足9秒的伤害3，8秒必须为2，虽然比要求的1多了造成了浪费但是为了满足9秒也要不得已而为之
// 如果某一秒需要的伤害值为1，更优的做法是认为前一秒没有施法
// 不过有人说这种贪心是错误的，可我实在没有想出哪里可能存在问题，每一种操作看似都是必须要这么做的
// 有个问题被我忽视掉了，仅按照靠后的来计算不一定可以满足前面的要求，为了满足后面前面可能产生多余的值，例如上面提到的9秒和8秒
// 同理，为了满足前面的，后面也可能产生多余，例如样例2，如果按照5秒的来，4秒的是不够的，为了满足4秒的，5秒需要多产生
// 而我考虑的做法并不能解决这个问题
// 正解是区间合并，但是实在没有相出这题和区间合并直接有什么关联
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> k[i];
    for (int i = 0; i < n; ++i) cin >> h[i];

    LL res = 0;
    int l = 1e9 + 10;
    for (int i = n - 1; ~i; --i)
        if (k[i] >= l) continue;
        else {
            l = k[i] - h[i] + 1;
            res += (1ll * h[i] * (h[i] + 1)) / 2;
        }
    
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