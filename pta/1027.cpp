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
constexpr int radix = 13;

string change(int c) {
    string res = "";
    if (!c) res += "0";
    while (c) {
        if (c % radix == 10) res += "A";
        else if (c % radix == 11) res += "B";
        else if (c % radix == 12) res += "C";
        else res += (c % radix) + '0';
        c /= radix;
    }
    if (res.size() == 1) res += "0";
    reverse(res.begin(), res.end());
    return res;
}
void solve() {
    int r, g, b;
    cin >> r >> g >> b;

    string res = "#";
    res += change(r);
    res += change(g);
    res += change(b);

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}