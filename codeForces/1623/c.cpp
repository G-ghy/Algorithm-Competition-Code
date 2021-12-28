/**
 * 这道题在分析过程中得到的一个问题是
 * 从3往n走，前面的不知道给它的前面多少，后面的也不知道要给前面多少
 * 面对这种局面，模拟是一定不可行的，因为没有任何一个策略可以决定到底给前面多少石头这件事
 * 然后考虑本题是最小值最大化，那么有可能是二分
 * 如果二分，无非是二分答案，即变化后的数中的最小值是多少。显然这个数可能的范围不会小于原序列中的min，不会大于原序列中的max，所以二分是有搜索范围的
 * 考虑是否有check策略，不能从前往后遍历，因为从前往后遍历后，后面还会给前面石头，前面在给它前面分石头时的数量就不再正确了
 * 所以一定是从后向前遍历，让后面的先把石头给出来，再让前面的给它前面的石头，但是需要注意的是，前面给它的前面石头时是不能够用后面分给它的石头的
 * 因为题目规定了分石头只能按照从3到n的顺序
 * 也就是说后面提前预支给前面的石头，影响了前面在跟给它前面的石头数量
 * 假设说前面在接收到后面分来的石头后，即使把它原有数量全部分配出去，也可以满足分配后石头数量>=规定的最小值
 * 但是如果没有接收到后面分来的时，可能它就不能把石头全部分出去
 * 所以后面提前分过来的时候影响了前面的分配策略，但是并不会用于前面的分配过程
 */
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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n;
int h[N], t[N];
int getFromBehind[N];

// 按照最小值为mid进行分配，判断最终的最小值是否>=mid
inline bool check(int mid) {
    for (int i = 1; i <= n; ++i) getFromBehind[i] = 0;
    for (int i = 1; i <= n; ++i) h[i] = t[i];
    // memset(getFromBehind, 0, sizeof getFromBehind);
    // memcpy(h, t, sizeof t);

    // for (int i = 0; i < 10; ++i) cout << "="; cout << endl;
    // cout << "mid = " << mid << endl;
    // for (int i = 1; i <= n; ++i) cout << h[i] << ' '; cout << endl;

    for (int i = n; i >= 3; --i) {
        if (getFromBehind[i] + h[i] <= mid) continue;
        int d = min(getFromBehind[i] + h[i] - mid, h[i]) / 3;
        
        getFromBehind[i - 2] += 2 * d;
        getFromBehind[i - 1] += d;
        h[i] -= 3 * d;

        // for (int i = 1; i <= n; ++i) cout << h[i] + getFromBehind[i] << ' '; cout << endl;
    }
    
    int minn = INF;
    for (int i = 1; i <= n; ++i) minn = min(minn, h[i] + getFromBehind[i]);

    // for (int i = 0; i < 10; ++i) cout << "="; cout << endl << endl;

    return minn >= mid;
}
void solve() {
    cin >> n;
    int l = INF, r = -INF;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        t[i] = h[i];
        l = min(l, h[i]);
        r = max(r, h[i]);
    }

    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}