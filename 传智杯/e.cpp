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

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

int n, k;
vector<int> a[N];

inline int getl(vector<int> a, int v) { // >= v的最小值下标
    int l = 0, r = a.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (a[mid] >= v) r = mid;
        else l = mid + 1;
    }
    return l;
}
inline int getr(vector<int> a, int v) { // <= v的最大值下标
    int l = 0, r = a.size() - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= v) l = mid;
        else r = mid - 1;
    }
    return l;
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int p;
            cin >> p;
            while (p--) {
                int x, y;
                cin >> x >> y;
                a[x].push_back(y);
            }
        } else {
            int x, ymin, ymax;
            cin >> x >> ymin >> ymax;
            sort(a[x].begin(), a[x].end());
            int l = getl(a[x], ymin), r = getr(a[x], ymax);
            if (a[x][l] >= ymin && a[x][r] <= ymax) cout << r - l + 1 << endl;
            else cout << 0 << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}