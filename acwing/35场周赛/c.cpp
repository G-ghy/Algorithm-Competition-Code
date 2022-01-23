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

constexpr int N = 3010;
constexpr int INF = 0x3f3f3f3f;

int n;
int s[N], c[N];
int pre[N], cur[N];

// 暴力做法是n^3的枚举，会超时
// 暴力之所以超时，是因为3重循环将i，j，k关联在一起了
// 但是k是多少与i无关，只与j有关(即找到关联变量之间的无关性是优化的关键)
// 这句话的意思是，如果选定了j，那么k应当为j之后比s[j]大的s[k]
// 说到这里不难想到可以预处理j之后比s[j]大的位置的c中的最小值
// 之后再预处理出j之前比s[j]小的位置中c中的最小值
// 当中间点选择c[j]时，和的最小值应当是这个位置前面比当前s值小的位置中c的最小值加上c[j]再加上后面符合条件中的c的最小值
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    
    memset(pre, 0x3f, sizeof pre);
    memset(cur, 0x3f, sizeof cur);

    for (int j = 0; j < n; ++j)
        for (int i = 0; i < j; ++i)
            if (s[i] < s[j]) pre[j] = min(pre[j], c[i]);

    for (int j = 0; j < n; ++j)
        for (int k = j + 1; k < n; ++k)
            if (s[j] < s[k]) cur[j] = min(cur[j], c[k]);

    int res = INF;
    for (int j = 0; j < n; ++j)
        res = min(res, pre[j] + c[j] + cur[j]);

    if (res == INF) res = -1;
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}