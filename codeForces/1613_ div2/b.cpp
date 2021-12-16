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

int a[N];

void solve() {
    int n;
    cin >> n;
    
    int minn = INF;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        minn = min(minn, a[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n && cnt < (n >> 1); ++i)
        if (a[i] != minn) {
            cout << a[i] << ' ' << minn << endl;
            ++cnt;
        }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}