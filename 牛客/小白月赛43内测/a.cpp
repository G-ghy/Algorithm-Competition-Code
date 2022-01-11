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

constexpr int N = 1010;
constexpr int INF = 0x3f3f3f3f;

int res[N];

inline vector<int> getFac(int x) {
    vector<int> fac;
    for (int i = 1; i <= x / i; ++i)
        if (!(x % i)) {
            fac.push_back(i);
            if (x / i != i) fac.push_back(x / i);
        }
    sort(fac.begin(), fac.end());

    return fac;
}
inline bool check(vector<int> &fac) {
    int m = fac.size();
    return !(fac[m - 1] % fac[((m - 1 + 2) >> 1) - 1]);
    // 题意理解错了，人家只说第m因子，没说所有因子
    // for (int i = 0; i < (int)fac.size(); ++i) {
    //     if (fac[i] % fac[((i + 2) >> 1) - 1]) return false;
    // }
    // return true;
}
inline void init(int n) {
    for (int i = 1; i <= n; ++i) {
        vector<int> fac = getFac(i);
        // if (check(fac)) {
        //     cout << i << " : ";
        //     for (int f : fac) cout << f << ' ';
        //     cout << '\n';
        // }
        if (check(fac)) res[i] = res[i - 1] + 1;
        else res[i] = res[i - 1];
    }
}
void solve() {
    int n;
    cin >> n;
    cout << res[n] << endl;
    // for (int i = 1; i <= n; ++i)
    //     cout << i << ' ' << res[i] << endl;
    // for (int i = 1; i <= n; ++i) {
    //     vector<int> fac = getFac(i);
    //     if (check(fac)) {
    //         cout << i << " : ";
    //         for (int f : fac) cout << f << ' ';
    //         cout << '\n';
    //     }
    // }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init(1000);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}