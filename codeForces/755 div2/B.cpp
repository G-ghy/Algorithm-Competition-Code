// 把图分成1*2 或 1*3的方格，怎么分数量最少
// n * m的放置方式分一次，m * n的放置方式分一次，两次取最小
// 每行的分分法相同，只需要考虑一行怎么分 * 行数
// 我觉得的原则：能拆开就拆开，能拆成1 * 3的就不拆成1 * 2的
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

constexpr int INF = 0x3f3f3f3f;

void solve_false() {
    int n, m;
    int res = INF;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << '*';
        cout << endl;
    }

    // n * m 的摆放方式
    // if (!((m % 3) % 2)) res = min(res, (m / 3 + (m % 3) / 2) * n); // 可以分割出1 * 3
    // else if (!(m % 2)) res = min(res, m / 2 * n); // 不能分割出1 * 3，但是可以分割出1 * 2的
    for (int i = 0; i <= m / 3; ++i) // 枚举每行分成1 * 3的个数
        if ((m - 3 * i) % 2 == 0) 
            res = min(res, (i + (m - 3 * i) / 2) * n);
    cout << res << endl;

    // m * n 的摆放方式
    // if (!((n % 3) % 2)) res = min(res, (n / 3 + (n % 3) / 2) * m);
    // else if (!(n % 2)) res = min(res, n / 2 * m);
    for (int i = 0; i <= n / 3; ++i)
        if ((n - 3 * i) % 2 == 0)
            res = min(res, (i + (n - 3 * i) / 2) * m);
    cout << res << endl;

    for (int i = 0; i < 10; ++i) cout << '-'; cout << endl;
}

void solve1() {
    int n, m;
    cin >> n >> m;
    cout << (n * m / 3) + (n * m % 3 > 0) << endl; // 余2还是1结果都+1
}
void solve2() {
    int n, m;
    cin >> n >> m;
    
    int sum = 0;
    if (!(m % 3)) {
        sum += n * (m / 3);
    } else if (m % 3 == 1) {
        sum += n * (m / 3);
        sum += (m % 3) * (n / 3);
        if (n % 3) ++sum; // n % 3 == 0(+0), 1(+1), 2(+1)
    } else if (m % 3 == 2) {
        sum += n * (m / 3);
        sum += (m % 3) * (n / 3);
        if (n % 3 == 1) ++sum; // 1 * 2
        else if (n % 3 == 2) sum += 2; // 2 * 2
    }

    cout << sum << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve2();
    return 0;
}