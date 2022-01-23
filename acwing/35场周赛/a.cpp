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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

inline void trans(string &a) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
}
void solve() {
    string a, b;
    cin >> a >> b;
    trans(a);
    trans(b);
    
    if (a < b) cout << "-1\n";
    else if (a == b) cout << "0\n";
    else cout << "1\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}