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

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n;
int primes[N], cnt;
bool st[N];
int inx[N];

// 这道题理论上应该推出2个性质就可以做了
// 1. 所以的质数对应的值必须不相等，因为质数两两互质
// 2. 不互质的两个数对应的值一定选相等的，这样对答案更有利

// 在做这道题时的突破点应该是我去打表看和2互质的有哪些数，当我在纸上列出2到20，并且把和2互质的数都标记上后，就注意到了没被标记那些数，
// 然后就想到了不互质的数可以选择相同的，并且根据2想到了用质数去划分哪部分数对应哪个值

// 所以对于不互质的数显然是根据它的最小质因子来确定的
// 当时做这道题的时候一门心思就在想互质的两个位置不能相等，然后其他数据一掺杂进来就彻底乱了
// 换个角度想一下可以发现“互质的不相等” <=> “不互质的就可以相等”
// 按照后面的理解显然就可以做了
// 互质的两个位置数不能一样，换个思考方向就是不互质的两个位置数据可以一样
// 筛出素数，从1开始标号
// 对于每个位置计算一下它的最小质因子，直接输出最小质因子对应的值
inline void init(int x) {
    for (int i = 2; i <= x; ++i) {
        if (!st[i]) primes[++cnt] = i;
        for (int j = 1; primes[j] <= x / i; ++j) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }

    for (int i = 1; i <= cnt; ++i) inx[primes[i]] = i;
}
inline int getMinPrimeFactor(int x) {
    for (int i = 1; i <= cnt; ++i)
        if (!(x % primes[i])) return primes[i];
    return 0;
}
void solve() {
    init(N);

    cin >> n;

    for (int i = 2; i <= n; ++i)
        cout << inx[getMinPrimeFactor(i)] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}