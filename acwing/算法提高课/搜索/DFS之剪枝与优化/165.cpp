/**
 * 和1118.分成互质组一样，两种思考方式
 * 1. 枚举每辆缆车上有哪些猫
 * 2. 枚举每只猫在哪个缆车上
 * 采用第2种枚举方式，对于每只猫考虑放在现有一组中或者新开一组，维护全局最小值
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20, INF = 0x3f3f3ff;

int n, w;
int a[N]; // 猫重
int gw[N], gcnt; // 每一组当前承重; 当前组数
int res;

void dfs(int u) {
    if (gcnt >= res) return;
    if (u == n) {
        res = min(res, gcnt);
        return;
    }
    // 考虑把猫放入已有组中
    for (int i = 0; i < gcnt; ++i)
        if (gw[i] + a[u] <= w) {
            gw[i] += a[u];
            dfs(u + 1);
            gw[i] -= a[u];
        }
    // 考虑把猫放入新的一组中
    gw[gcnt++] += a[u];
    dfs(u + 1);
    gw[--gcnt] -= a[u];
}
void solve() {
    cin >> n >> w;
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 重量越大的猫可选择的空间较小，则其对应的搜索树中的分支相对较少，搜索过程会更快
    sort(a, a + n, [](int a, int b) -> bool {return a > b;});
    gcnt = 0;
    res = INF;
    dfs(0);

    cout << res << endl;

    return;
}
int main() {
    solve();
    return 0;
}