#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int map[100];
void solve() {
    map['A' - '0'] = 1;
    map['1' - '0'] = 10;
    for (int i = 0; i <= 9; ++i)
        if (i != 1) map[i] = i;
    
    string str;
    int res = 0;
    cin >> str;
    for (char c : str)
        res += map[c - '0'];

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}