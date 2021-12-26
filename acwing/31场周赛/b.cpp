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

constexpr int N = 30;
constexpr int INF = 0x3f3f3f3f;

int n;
int a[N], cnt;

inline void getA(int x) {
    while (x) {
        a[cnt++] = x % 10;
        x /= 10;
    }
}
void solve() {
    cin >> n;
    getA(n);

    int pos;
    for (pos = cnt - 1; ~pos; --pos)
        if (a[pos] > 1) break;
    
    for (int i = pos; ~i; --i) a[i] = 1;

    int basic = 1, res = 0;
    for (int i = 0; i < cnt; ++i) {
        if (a[i]) res += basic;
        basic *= 2;
    }

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}