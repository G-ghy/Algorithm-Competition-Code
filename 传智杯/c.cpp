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

constexpr int N = 1010;
constexpr int INF = 0x3f3f3f3f;

int n;
double a[N];

void solve() {
    cin >> n;
    double minn = INF, maxx = -INF;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        minn = min(minn, a[i]);
        maxx = max(maxx, a[i]);
    }

    for (int i = 0; i < n; ++i)
        if (!i) printf("%d", (int)((a[i] - minn) * 100 / (maxx - minn)));
        else printf(" %d", (int)((a[i] - minn)  * 100 / (maxx - minn)));
}
int main() {
    solve();
    return 0;
}