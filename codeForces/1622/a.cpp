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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    bool flag = false;

    if (b == c) flag = ((a % 2 == 0) || (a == b + c));
    else flag = (a == b + c);

    if (flag) {
        cout << "YES" << '\n';
        return;
    }

    if (a == c) flag = ((b % 2 == 0) || (b == a + c));
    else flag = (b == a + c);

    if (flag) {
        cout << "YES" << '\n';
        return;
    }

    if (a == b) flag = ((c % 2 == 0) || (c == a + b));
    else flag = (c == a + b);

    if (flag) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}