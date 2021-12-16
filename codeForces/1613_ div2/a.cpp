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

inline string getn(int x, int p) {
    string res = "";
    res += to_string(x);
    while (p--) res += "0";
    return res;
}
int compare(string &a, string &b) {
    int la = a.size(), lb = b.size();
    if (la > lb) return 1;
    if (la < lb) return -1;
    for (int i = 0; i < la; ++i)
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    return 0; 
}
void solve() {
    int x, p1, p2;
    string x1, x2;

    cin >> x >> p1;
    x1 = to_string(x);
    
    cin >> x >> p2;
    x2 = to_string(x);

    int l1 = x1.size(), l2 = x2.size();

    int flag;
    if (l1 + p1 > l2 + p2) flag = 1;
    else if (l1 + p1 < l2 + p2) flag =  -1;
    else {
        if (l1 == l2) {
            if (x1 > x2) flag = 1;
            else if (x1 < x2) flag = -1;
            else flag = 0;
        } else {
            bool turn = false;
            if (l1 > l2) {
                turn = true;
                swap(x1, x2);
                swap(l1, l2);
                swap(p1, p2);
            }
            for (int i = 0; i < l2 - l1; ++i) x1 += "0";
            if (x1 > x2) flag = turn ? -1 : 1;
            else if (x1 < x2) flag = turn ? 1 : -1;
            else flag = 0;
        }
    }

    if (flag > 0) cout << ">" << endl;
    else if (!flag) cout << "=" << endl;
    else cout << "<" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}