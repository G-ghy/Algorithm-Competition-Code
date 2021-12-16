#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int N = 1e5 + 10;

int n, m;
int a[N];

bool check(int mid) {
    int cnt = 0;
    for (int i = 1; i < N; ++i) {
        cnt += a[i] / mid;
        if (a[i] % mid) ++cnt;
    }
    
    return cnt <= m;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }
    
    int res = -1;
    int l = 1, r = 100000;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
            res = mid;
        }
        else l = mid + 1;
    }

    cout << res << endl;
}
int main() {
    memset(a, 0, sizeof a);
    solve();
    return 0;
}