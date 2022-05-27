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
#include <cstring>

using namespace std;

constexpr int N = 55;
constexpr int INF = 0x3f3f3f3f;

int n;
int len;
int cnt;
string res[N];

inline int getLen(int x) {
    int len = 0;
    if (!x) len = 1;
    while (x > 0) {
        ++len;
        x /= 10;
    }
    return len;
}
void dfs(int u, string id) {
    if (u == len + 1) return;
    for (int i = 0; i <= 9; ++i) {
        if (u == 1 && !i) continue;
        string t = id + to_string(i);

        if (stoi(t) <= n && cnt < 50)
            res[cnt++] = t;
            
        dfs(u + 1, t);
    }
}
void solve() {
    cin >> n;
    
    cnt = 0;
    len = getLen(n);

    dfs(1, "");

    for (int i = 0; i < 50; ++i) cout << (res[i] + ".mp4") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}