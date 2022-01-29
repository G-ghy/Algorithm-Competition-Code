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

constexpr int N = 30010;
constexpr int INF = 0x3f3f3f3f;

// 在不考虑距离时就是一般的并查集
// 对于维护距离，其实我想的也是维护到根节点的距离
// 之后需要考虑的是合并操作和find过程中都需要维护哪些信息
// 首先并查集一定需要p数组存储父节点，到根节点的距离采用d进行存储
// 容易出错的地方是，对于合并操作，真的按照题目说的将一列的值放到另一列的最下方，如果这样想，那么一定会这样操作
// 设一列的根节点是px，另一列最下方是y，p[px] = y， 这样想这个y是没办法维护的，这样想带来的影响还包括对于d的更新，我想的是d[px] = d[y]，问题还是出在y无法维护上面
// 实际的做法是，一列放到另一列的最下方这仅是逻辑上操作，并非物理上真的这样存储，我们通过维护数据可以保证计算出的结果反映出来的就是这样的存储形式
// 需要考虑的是在两个点判定处不再同一列应当如何处理 和 在find过程中应当如何处理
// 两个点x，y如果不再同一列，那么假设将x所在列的点放置到y所在列的最下方，那么需要维护的是
// 1. p[px] = py
// 2. d[px] = size[py](y所在列中点的数量)，这里仅需要修改x列最上方的顶点的d值，其余值会在路径压缩过程中得到更新
// find过程需要处理的是
// 1. 首先找到路径压缩后的根节点root
// 2. 更新x节点的d值，上一步完成后，px到root的各个值都已经更新完成，所以x到root的距离等于x到px的距离加上px到root的距离，即d[x] = d[x] + d[px]
// 3. 最后更新p[x]

int p[N], d[N], s[N]; // d:某节点到根节点之间的节点数量 s:某列中节点数量

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}
void solve() {
    int T;
    cin >> T;

    for (int i = 0; i < N; ++i) {
        p[i] = i;
        s[i] = 1; // 每一列最初都有一个节点
    }

    while (T--) {
        char type;
        int a, b;

        cin >> type >> a >> b;
        int pa = find(a), pb = find(b);

        if (type == 'M') {
            p[pa] = pb;
            d[pa] = s[pb];
            s[pb] += s[pa];
        } else {
            int res = (pa != pb) ? -1 : max(0, abs(d[a] - d[b]) - 1); // 当a == b时结果应当为0，但是减1会使得结果变为-1，所以同0取max
            cout << res << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}