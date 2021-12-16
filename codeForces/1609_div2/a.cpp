// 一个数除以2，一个数乘2，那不就等价于把一个数的2给到另一个数吗，现在的问题就是把所有的2给谁最合适
// 显然是把所有的2给最大的值最优，就是把所有数的因子2都除尽，剩下值最大的就是那个接受2的数
// 我的问题是一开始就陷入到了奇偶的问题上，下次遇到这种除以几的问题可以从因子的角度考虑一下

// 对于最开始的想法
// 当时是证明得到如果存在两个数x(满足x|2)和y，如果满足x<=2y，那么x/2 + y >= x + y
// 如果偶数中不存在>2*最大奇数的数，则选择把2都放到最大奇数上，反之放到最大偶数上
// 对于数据4 16 5，按照你的思想，由于16 > 2 * 5，因此不选择把2都放到5上，而是都放到16上，但是显然把2都放到5上才是最佳的
// 你错在并没有真的证明如果16>2*5，把2放到16上是优与放到5上的这一结论
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
using LL = long long;

constexpr int N = 20;
constexpr int INF = 0x3f3f3f3f;

int n;
LL num[N], a[N];

inline int getTimes(int x) {
    int cnt = 0;
    while (!(x & 1)) {
        ++cnt;
        x >>= 1;
    }
    return cnt;
}
void solve() {
    memset(a, 0, sizeof a);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> num[i];

    int t = 0;
    for (int i = 0; i < n; ++i) {
        int k = getTimes(num[i]);
        t += k;
        a[i] = num[i] / (1ll << k);
    }

    sort(a, a + n);

    a[n - 1] *= 1ll << t;
    LL res = 0;
    for (int i = 0; i < n; ++i) res += a[i];

    cout << res << endl;
    // int maxx = -1;
    // for (int i = 0; i < n; ++i) {
    //     a[i] = num[i] / (1 << getTimes(num[i]));
    //     if (maxx == -1 || a[i] > a[maxx])
    //         maxx = i;
    // }

    // LL res = 0;
    // int t = 0;
    // for (int i = 0; i < n; ++i)
    //     if (i != maxx) {
    //         int k = getTimes(num[i]);
    //         t += k;
    //         res += num[i] / (1ll << k);
    //     }

    // res += num[maxx] * (1ll << t);

    // cout << res << endl;
}
// void solve2() {
//     even.clear();
//     odd.clear();

//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         int x;
//         cin >> x;
//         if (x & 1) odd.push_back(x);
//         else even.push_back(x);
//     }
    
//     sort(even.begin(), even.end());
//     sort(odd.begin(), odd.end());
//     if (!odd.size()) {
//         odd.push_back(even.back());
//         even.pop_back();
//     }
    
//     bool flag = false;
//     for (int i = 0; i < (int)even.size(); ++i)
//         if (even[i] > 2 * odd.back()) {
//             flag = true;
//             break;
//         }
//     if (flag) {
//         LL &b = even.back();
//         for (int i = 0; i < (int)even.size() - 1; ++i) {
//             LL &a = even[i];
//             int t = getTimes(a);
//             a /= 1 << t;
//             b *= 1 << t;
//         }
//     } else {
//         LL &b = odd.back();
//         for (int i = 0; i < (int)even.size(); ++i) {
//             LL &a = even[i];
//             int t = getTimes(a);
//             a /= 1 << t;
//             b *= 1 << t;
//         }
//     }

//     LL res = 0;
//     for (int i = 0; i < (int)even.size(); ++i) res += even[i];
//     for (int i = 0; i < (int)odd.size(); ++i) res += odd[i];
//     for (int i = 0; i < (int)even.size(); ++i) cout << even[i] << ' '; cout << endl;
//     for (int i = 0; i < (int)odd.size(); ++i) cout << odd[i] << ' '; cout << endl;
//     cout << res << endl;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}