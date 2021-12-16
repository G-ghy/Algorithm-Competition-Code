#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using LL = long long;

LL x, n;

void solve() {
    cin >> x >> n;
    if (x & 1) {
        LL s = n / 4 * 4 + 1;
        LL a[] = {0, s, -(s + 1), -(s + 2), s + 3};
        for (int i = 0; i <= n % 4; ++i) x += a[i];
    } else {
        LL s = n / 4 * 4 + 1;
        LL a[] = {0, -s, s + 1, s + 2, -(s + 3)};
        for (int i = 0; i <= n % 4; ++i) x += a[i];
    }
    cout << x << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}