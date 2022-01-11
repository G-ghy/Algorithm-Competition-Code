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
using LL = long long;

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

inline bool check(LL n) {
    int cnt4 = 0, cnt7 = 0;
    while (n) {
        int x = n % 10;
        if (x == 4) ++cnt4;
        else if (x == 7) ++cnt7;
        n /= 10;
    }
    return (cnt4 + cnt7 == 4 || cnt4 + cnt7 == 7);
}
void solve() {
    LL n;
    cin >> n;
    cout << (check(n) ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}