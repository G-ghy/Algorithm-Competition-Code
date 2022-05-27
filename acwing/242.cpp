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

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int a[N];

inline int lowbit(int x) {

}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];

    while (m--) {
        char op;
        cin >> op;
        if (op == 'C') {
            int l, r, d;
            cin >> l >> r >> d;

        } else {
            int x;
            cin >> x;
            cout << get(x) << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}