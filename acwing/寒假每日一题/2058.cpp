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

constexpr int N = 40;
constexpr int INF = 0x3f3f3f3f;

inline int getDecimal(string str, int base) {
    int res = 0, val = 1;
    for (int i = (int)str.size() - 1; ~i; --i) {
        if (str[i] == '1') res += val;
        val *= base; 
    }
    return res;
}
inline string getTernary(int decimal) {
    string res = "";
    while (decimal) {
        res += (decimal % 3) + '0';
        decimal /= 3;
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}
inline bool check(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < (int)s1.size(); ++i)
        if (s1[i] != s2[i]) ++cnt;
    
    return (cnt == 1);
}
void solve() {
    string binary, ternary;

    cin >> binary >> ternary;

    for (int i = 0; i < (int)binary.size(); ++i) {
        string bt = binary;
        bt[i] = ((bt[i] - '0') ^ 1) + '0';

        int decimal = getDecimal(bt, 2);

        if (check(getTernary(decimal), ternary)) {
            cout << decimal << '\n';
            break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}