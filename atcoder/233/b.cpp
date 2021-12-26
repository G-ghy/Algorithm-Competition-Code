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
    int l, r;
    string s;

    cin >> l >> r >> s;

    string t = s.substr(l - 1, r - l + 1);
    reverse(t.begin(), t.end());
    
    string res = s.substr(0, l - 1) + t + s.substr(r);
    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}