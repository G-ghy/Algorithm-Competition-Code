#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int basic = 1, sum = 0;
    for (int i = 1; i <= n; ++i) {
        basic *= i;
        sum += basic;
    }

    cout << sum << '\n';
}
int main() {
    solve();
    return 0;
}