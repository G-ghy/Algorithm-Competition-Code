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
#include <fstream>

using namespace std;

constexpr int N = 2e6 + 10;
constexpr int INF = 0x3f3f3f3f;

inline bool isPirme(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i)
        if (x % i == 0) return false;
    return true;
}
inline int getMinPrime(int x) {
    for (int i = 2; ; ++i)
        if (isPirme(i) && x % i != 0) return i;
}
// 第一次错想为gcd(x[i -1], x[i])==x[i]，那么让res[i]为x[i]即可
// 我上面的分析就错了
// 对于res[i], 去找x[i-1]质因数分解结果中没有的质数，乘以x[i]即为res[i]
// void solve() {
//     int n;
//     cin >> n;
//     int x, pre;
//     for (int i = 0; i < n; ++i) {
//         cin >> x;
//         if (!i) cout << x;
//         else cout << ' ' << x * getMinPrime(pre);
//         pre = x;
//     }
//     cout << endl;
// }

inline int gcd(int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// int x[15];
int x[N];
bool st[N];
// x一定是减小的
// x[0]不一定是n
void solve() {
    // ofstream os;
    // os.open("out.txt", ios::out);

    // int n;
    // cin >> n;
    // vector<int> a;
    // for (int i = 1; i <= n; ++i) a.push_back(i);
    // for (int i = 0; i < n; ++i) cin >> x[i];

    // do {
    //     if (a[0] != x[0]) continue;
    //     bool flag = true;
    //     for (int i = 1; i < n; ++i)
    //         if (gcd(a[i], x[i - 1]) != x[i]) {
    //             flag = false;
    //             break;
    //         }

    //     if (flag) {
    //         for (int i = 0; i < n; ++i) os << a[i] << ' ';
    //         os << endl;
    //     }
    // } while(next_permutation(a.begin(), a.end()));

    // int cnt = 0;
    // do {
    //     // if (a[0] < 10) continue;
    //     // if (++cnt > 30000) break;
    //     for (int i = 0; i < n; ++i)
    //         if (!i) os << a[i] << ' ';
    //         else os << a[i] << ' ';
    //     os << " ----> ";

    //     for (int i = 0; i < n; ++i)
    //         if (!i) os << a[i] << ' ';
    //         else {
    //             int res;
    //             for (int j = 0; j <= i; ++j) 
    //                 if (!j) res = a[j];
    //                 else res = gcd(res, a[j]);
    //             os << res << ' ';
    //         }
    //     os << endl;
    // } while(next_permutation(a.begin(), a.end()));

    // os.close();

    // int n;
    // cin >> n;
    // for (int i = 1; i <= n; ++i) cin >> x[i];

    // int p = 1, v = 1;
    // for (int i = 1; i <= n; ++i) {
    //     if (i == 1) {
    //         cout << x[i] << ' ';
    //         st[x[i]] = true;
    //     } else if (x[i] == 2) {
    //         while (p <= n) {
    //             if (!st[p] && !(p & 1)) {
    //                 st[p] = true;
    //                 cout << p << ' ';
    //                 ++p;
    //                 break;
    //             }
    //             ++p;
    //         }
    //     } else {
    //         while (v <= n) {
    //             if (!st[v]) {
    //                 cout << v << ' ';
    //                 ++v;
    //                 break;
    //             }
    //             ++v;
    //         }
    //     }
    // }
    //     cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}