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

constexpr int N = 50010;
constexpr int INF = 0x3f3f3f3f;

int n, k;
int p[N], d[N];

// 本题包含3种关系
// 1. 吃
// 2. 被吃
// 3. 同类
// 按照带边权并查集的方法，边权分为3种，定义为
// 1. 与根节点距离1，吃根节点
// 2. 与根节点距离为2，被根节点吃
// 3. 与根节点距离为3(%3下为0)，与根节点同类
// 容易忽视的一点是A 吃 B，B 吃 C，C 吃 A，得到其中任意两个条件即可得到另一个条件，不过想题目时不需要单独去考虑这件事，正常思考即可
int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}
void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) p[i] = i;

    int res = 0;
    while (k --) {
        int type, x, y;
        cin >> type >> x >> y;
        if (x > n || y > n) {
            ++res;
            continue;
        }
        int px = find(x), py = find(y);
        if (type == 1) { // 给定x和y是同类关系，
            if (px != py) {
                p[px] = py;
                d[px] = (d[y] - d[x] + 3) % 3;
            } else if ((d[x] - d[y]) % 3) ++res; // 已经存在关系，检查是否是同类关系,由于这里是描述相对关系，因此采用减法
        } else { // 给定x吃y
            if (x == y) {
                ++res;
                continue;
            }
            if (px != py) {
                p[px] = py;
                d[px] = (d[y] - d[x] + 1 + 3) % 3;
            } else if ((d[x] - d[y] + 3) % 3 != 1) ++res;
        }
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}