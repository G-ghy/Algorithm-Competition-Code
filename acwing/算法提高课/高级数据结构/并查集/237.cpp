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

int ep[N], nep[N];

int find(int x, int p[], int op) {
    if (p[x] != x) p[x] = find(p[x], p, op);
    return p[x];
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) ep[i] = i;
    for (int i = 1; i <= n; ++i) nep[i] = i;

    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        int a, b, op;
        cin >> a >> b >> op;
        int epa = find(a, ep, op), epb = find(b, ep, op);
        int nepa = find(a, nep, op), nepb = find(b, nep, op);
        if (op) {
            if (nepa == nepb) {
                flag = false;
                break;
            }
            ep[epa] = epb;
        } else {
            if (epa == epb) {
                flag = false;
                break;
            }
            nep[nepa] = nepb;
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

ep[1] = 1意味着1 == 1是正确的
nep[1] = 1意味着1 != 1这不对呀，不管是现在的写法还是说把0和1的操作分开来看，对于nep的初始化问题一直都在
5
2
1 2 1
1 2 0
3
1 2 1
2 3 1
3 1 1
4
1 2 1
2 3 1
3 4 1
1 4 0
2
1 2 1
2 1 1
1
1 1 1

output:
NO
YES
NO
YES
NO

right:
NO
YES
NO
YES
YES