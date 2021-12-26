// 通过画图写伪代码发现按照一定顺序答案是固定的
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

int n;
int r[N], c[N];
char inx[N];
int priority[N];

inline void init() {
    int l = 1, r = n;
    bool is_r = true;
    for (int i = 1; i <= n; ++i) {
        if (is_r) {
            priority[r] = i;
            is_r = false;
            --r;
        } else {
            priority[l] = i;
            is_r = true;
            ++l;
        }
    }
    
    for (int i = 1; i <= n / 2; ++i) inx[i] = '.';
    for (int i = n / 2 + 1; i <= n; ++i) inx[i] = '#';
}
inline char getRes(int row, int col) {
    int basic = (priority[row] < priority[col]) ? row : col;
    return inx[basic];
    // int l = 1, r = n;
    // bool is_r = true;
    // char res = '#';
    // while (l < r) {
    //     if (is_r) {
    //         if (row == r || col == r) return res;
    //         is_r = false;
    //         res = '.';
    //         --r;
    //     } else {
    //         if (row == l || col == l) return res;
    //         is_r = true;
    //         res = '#';
    //         ++l;
    //     }
    // }
    // return res;
}
void solve() {
    cin >> n;
    init();
    for (int i = 1; i <= n; ++i) cin >> r[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) cout << getRes(r[i], c[j]);
    //     cout << endl;
    // }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << getRes(r[x], c[y]);
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}