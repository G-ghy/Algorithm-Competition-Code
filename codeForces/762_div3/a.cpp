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

void solve() {
    string str;
    cin >> str;
    if (str.size() & 1) {
        cout << "NO" << endl;
        return;
    }
    string first = str.substr(0, (int)str.size() >> 1);
    string second = str.substr((int)str.size() >> 1);

    if (first == second) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}