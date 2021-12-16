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

int n, a, b;

inline int check(int a, int b) {
    if (a + b > n - 2 || abs(a - b) > 1) return -1;
    if (a < b) return 0;
    return 1;
}
void solve() {
    cin >> n >> a >> b;

    int flag = check(a, b);
    if (flag == -1) {
        cout << -1 << endl;
        return;
    }

    int l = 1, r = n;
    if (!flag) { // a < b
        for (int i = 0; i < b; ++i) {
            cout << r << ' ' << l << ' ';
            --r; ++l;
        }
        for (int i = l; i <= r; ++i) cout << i << ' ';
    } else { // a > b || a == b
        for (int i = 0; i < a; ++i) {
            cout << l << ' ' << r << ' ';
            --r; ++l;
        }
        for (int i = r; i >= l; --i) cout << i << ' ';
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}