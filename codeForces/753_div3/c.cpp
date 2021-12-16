#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using LL = long long;

constexpr int N = 2e5 + 10;

int n;
LL a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n, [](int a, int b) -> bool {return a > b;});
    
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    LL cg = 0;
    int pos = -1;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] - cg <= a[i - 1] - a[i])
            cg += a[i] - cg;
        else {
            pos = i;
            break;
        }
    }
    if (pos == -1) cout << (a[0] - cg) << endl;
    else cout << (a[pos] - cg) << endl;

    return;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}