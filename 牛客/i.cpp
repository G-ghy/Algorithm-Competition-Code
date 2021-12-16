// n实在太小了，全排列枚举所有方案，检查有几种合法方案
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

constexpr int N = 20;

int n;
int request[N];
bool st[N];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &request[i]);

    string str = "";
    for (int i = 1;  i <= n; ++i) str += i + '0';
    
    int cnt = 0;
    bool flag;
    do {
        flag = true;
        memset(st, 0, sizeof st);
        for (int i = 0; i < str.size(); ++i) {
            int inx = str[i] - '0';
            st[inx] = true;
            if (request[inx] == inx) continue;
            if (st[request[inx]]) {
                flag = false;
                break;
            }
        }
        if (flag) ++cnt;
    } while(next_permutation(str.begin(), str.end()));
    
    cout << cnt << endl;
}
int main() {
    solve();
    return 0;
}