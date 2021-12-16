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

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

string str;

void solve() {
    cin >> str;
    int n = (int)str.size();
    int h = (n + 2) / 3;
    int l = 0, r = n - 1;
    for (int i = 0; i < h - 1; ++i) {
        cout << str[l];
        for (int i = 0; i < n - 2 * h; ++i) cout << ' ';
        cout << str[r] << endl;
        ++l, --r;
    }
    for (int i = l; i <= r; ++i) cout << str[i];
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}