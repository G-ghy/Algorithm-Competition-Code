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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

// 其实不能完全算我自己想出来的
// 因为我在面对如何确定次数时并没有想到一个比较好的策略
// 我并没有考虑到把一个瓶子的东西倒入另一个瓶子之后总量并没有发生变化
// 而恰恰是通过这个来确定需要翻倍的次数的
// 假设 2 4 90
// 想要让一个瓶子的量为90，至少需要满足两个瓶子的总量>=90(这个逻辑是我自己想的)
// 根据一次两个瓶子相互倒总量不变，只需要考虑几次翻倍可以使得总量>=90
// 90 / 6 = 15...0
// 6 * 15 >= 90
// 但是需要注意的是翻倍的过程是这样的：
// 6 * 2 = 12
// 12 * 2 = 24 （6 * 2^2 = 24）
// 24 * 2 = 48 （6 * 2^3 = 48)
// ...
// 也就是说我们需要计算的是满足2^k >= 15的最小的k值，k即为答案
// 还需要注意的是假设为95 / 6 = 15...5
// 不能整除这种情况，如果想满足总量>=95，需要找到2^k >= (15 + 1 = 16) 的最小的k值
void solve() {
    LL a, b, target;

    cin >> a >> b >> target;

    if (a == target || b == target) {
        cout << "0\n";
        return;
    }
    if (target & 1) {
        cout << "-1\n";
        return;
    }
    // 这里想错了，因为可以一直翻倍，按你说的只能翻倍一次
    // if (a + b < target) cout << -1 << '\n';
    // else cout << 1 << '\n';
    LL times = target / (a + b);
    if (!times) {
        cout << "1\n";
        return;
    }
    if (target % (a + b)) ++times;

    // 需要注意1需要用long long，否则评测的结果可能是TLE
    int res;
    for (res = 0; (1ll << res) < times; ++res);
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