#include <iostream>

using namespace std;

constexpr int up = 6, down = 4, wait = 5;
int n;

void solve() {
    int storey;
    int res = 0, pos = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> storey;
        res += (storey > pos) ? (storey - pos) * up: (pos - storey) * down;
        res += wait;
        pos = storey;
    }
    cout << res << endl;
}
int main() {
    solve();
    return 0;
}