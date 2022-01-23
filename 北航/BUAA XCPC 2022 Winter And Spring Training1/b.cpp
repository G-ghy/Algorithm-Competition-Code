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

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, x;
int a[N];

// 不难发现的是
// 纵坐标的变化没什么用处，因为纵坐标从0开始最后还是回到0
// 需要关注的是横坐标，对于给定的可走距离，设其最小值为min，最大值为max
// 显然min和max之间的距离都可以走到，对于区间内给定的距离一次可以走到，没有给定的距离2次可以走到(需要经历一个中间点)
// 所以问题就转化为了如何通过最少的给定数值凑出目标值

// 我思考的问题还是很多的
// 只要底边长度确定了，由于高度可以为任意值，所以斜边的长度是可以任意构造的
// 假设想走到x，且通过走等边三角形的方式，对于一半三角形，底边长度为x/2，通过修改高度，任意长度>x/2的斜边都是可以构造出来的
// 我想的是<max(ai)的长度如果存在a中就可以通过1步走到，不存在a中的可以通过构造三角形2步走到
// 我想的是确定了斜边的长度后改变高度可以确定出底边的长度
// 给定方法是确定了底边长度，通过改变高度可以构造出合法的斜边长度
void solve() {
    cin >> n >> x;
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == x) flag = true;
    }

    sort(a + 1, a + n + 1);
    
    if (flag) cout << "1\n";
    else {
        if (x <= 2 * a[n]) cout << "2\n";
        else {
            // int res = 0;
            // for (int i = n; i; --i) {
            //     if (a[i] > x) continue;
            //     res += x / a[i];
            //     x %= a[i];
            // }
            // if (x) res += 2;
            // cout << res << '\n';
            cout << (x + a[n] - 1) / a[n] << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}