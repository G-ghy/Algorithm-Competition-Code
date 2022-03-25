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

char mapping[] = {'A', 'B', 'C', 'D', 'E', 'F'};

string get16(int x) {
    string res = "";
    if (!x) res = "0";
    while (x) {
        int t = x % 16;

        if (t >= 10) res += mapping[t - 10];
        else res += to_string(t);
        
        x /= 16;
    }

    return res;
}
void solve() {
    int n;
    cin >> n;

    string sn = get16(n);

    int res = 0;
    for (char c : sn) {
        if (c == '0' || c == '4' || c == '6' || c == '9' || c == 'A' || c == 'D') res += 1;
        else if (c == '8' || c == 'B') res += 2;
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}