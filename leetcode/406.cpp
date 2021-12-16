#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

void solve() {
    int a = 0;
    int b[] = {3, 2, 1};

    sort(b, b + 3, [&](int c, int d) -> bool {
        cout << a << endl;
        ++a;
        return c < d;
    });

    for (int i = 0; i < 3; ++i) cout << b[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}