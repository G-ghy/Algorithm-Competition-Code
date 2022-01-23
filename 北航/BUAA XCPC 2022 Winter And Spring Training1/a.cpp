// #include <cstring>
// #include <cstdio>
// #include <cmath>
// #include <iostream>
// #include<string>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <stack>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;

// constexpr int N = 2e5 + 10;
// constexpr int INF = 0x3f3f3f3f;

// int n;
// int a[N];

// inline bool find() {
//     int l = 1, r;
//     for (r = 1; r <= n; ++r) {
//         if (a[r] - a[l] >= r - l + 1) {
//             cout << "YES\n";
//             cout << l << ' ' << r << '\n';
//             return true;
//         }
//         if ((a[r] < a[l])) l = r;
//         else if (a[r] - a[l] <= r - l) l = r;
//     }
//     return false;
// }
// void solve() {
//     cin >> n;
//     for (int i = 1; i <= n; ++i) cin >> a[i];

//     bool flag = find();
//     if (!flag) {
//         reverse(a + 1, a + n + 1);
//         // 错误原因，翻转后即使找到答案但是下标是错误的
//         flag = find();
//     }
    
//     if (!flag) cout << "NO" << endl;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     int T;
//     cin >> T;
//     while (T--) solve();
//     return 0;
// }

// 维护的是两个值和距离之间的关系
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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n;
int a[N];

inline bool find() {
    int l = 1, r;
    for (r = 1; r <= n; ++r) {
        if (a[r] - a[l] >= r - l + 1) {
            cout << "YES\n";
            cout << l << ' ' << r << '\n';
            return true;
        }
        if (a[r] <= a[l]) l = r;
        else if (a[r] - a[l] <= r - l) l = r;
    }
    return false;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // 右-左，更新左边界
    int l = 1, r;
    for (r = 1; r <= n; ++r) {
        if (a[r] - a[l] >= r - l + 1) {
            cout << "YES\n";
            cout << l << ' ' << r << '\n';
            return;
        }
        if (a[r] <= a[l]) l = r;
        else if (a[r] - a[l] <= r - l) l = r;
    }

    // 左-右，更新右边界
    r = n;
    for (l = n; l; --l) {
        if (a[l] - a[r] >= r - l + 1) {
            cout << "YES\n";
            cout << l << ' ' << r << '\n';
            return;
        }
        if (a[l] <= a[r]) r = l;
        else if (a[l] - a[r] <= r - l) r = l;
    }

    cout << "NO" << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}