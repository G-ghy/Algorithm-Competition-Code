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
    int n, m, rb, cb, rd, cd;

    cin >> n >> m >> rb >> cb >> rd >> cd;

    int minR;
    if (rd < rb) minR = n - rb + n - rd;
    else minR = rd - rb;

    int minC;
    if (cd < cb) minC = m - cb + m - cd;
    else minC = cd - cb;

    cout << min(minR, minC) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}