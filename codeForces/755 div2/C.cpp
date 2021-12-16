// 选择A序列中的某些值加一能否使得A序列变为B序列
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

constexpr int N = 110;

int n;
int a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    bool flag = true;
    for (int i = 0; i < n; ++i)
        if ((b[i] - a[i]) != 0 && (b[i] - a[i]) != 1) {
            flag = false;
            break;
        } 
    
    cout << ((flag) ? "YES" : "NO") << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}