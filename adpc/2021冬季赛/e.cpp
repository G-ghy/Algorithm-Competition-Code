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

int n, k;

void solve() {
    cin >> n >> k;

    LL res = n;
    for (int i = 0; i < k; ++i) {
        int interest = min(res / 10, 5ll);
        res += interest + 5;
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}