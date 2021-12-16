// 这样写没有问题，但是pat上报段错误，1018的段错误是dfs没加剪枝导致的
// 这次按照我现在的写法没法去掉什么东西了，而且这完全是纯C的写法，细节太多，很容易出错，考试调出来的可能性不大，换种写法吧
// 除了细节太多，复杂度也不是最优的，每次找点都需要遍历
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <cmath>

// using namespace std;

// constexpr int N = 35, M = N * N / 2;
// constexpr int INF = 0x3f3f3f3f;

// int n;
// int h[N], e[M], ne[M], idx;
// int post[N], in[N]; // post：后序，in：中序
// int q[N], hh, tt;

// void add(int a, int b) {
//     e[idx] = b;
//     ne[idx] = h[a];
//     h[a] = idx++;
// }
// // 对于给定的后续遍历和中序遍历进行建树，根节点为preRoot
// void construct(
//     int post[], int post_l, int post_r, 
//     int in[], int in_l, int in_r, 
//     int preRoot) {
    
//     if (post_l > post_r || in_l > in_r) return;
//     int root = post[post_r];

//     // 这项工作可以通过哈希反向映射预处理出来
//     // 确定在中序遍历中根节点位置rootPos
//     int rootPos;
//     for (rootPos = in_l; rootPos <= in_r; ++rootPos)
//         if (in[rootPos] == root) break;

//     // 这项工作可以利用性质”某根结点的左子树或右子树在中序遍历和后序遍历中长度是一样的“通过计算直接求解出来
//     // 在后续遍历中确定左右子树的分界线border
//     int st = 0;
//     int border = INF; // 从border到post_r-1就是post中右子树对应的区间
//     for (int i = rootPos + 1; i <= in_r; ++i) st |= 1 << in[i]; // 把右子树节点进行标记以便在post中找到左右子树的分界
//     for (int i = post_l; i <= post_r; ++i)
//         if (st >> post[i] & 1) {
//             border = i;
//             break;
//         }
    
//     if (preRoot != -1) add(preRoot, root);
//     // 先建立的点最后在链式前向星的存储结构中处在后面，需要先输出左子树的点，因此左子树要后建立
//     if (border == INF) // 说明中序遍历中根节点右侧没有点，根节点没有右子树，不代表没有左子树
//         border = post_r; // post中根节点位置
//     construct(post, border, post_r - 1, in, rootPos + 1, in_r, root); // 右子树
//     construct(post, post_l, border - 1, in, in_l, rootPos - 1, root); // 左子树
// }
// void solve() {
//     cin >> n;
//     for (int i = 0; i < n; ++i) cin >> post[i];
//     for (int i = 0; i < n; ++i) cin >> in[i];

//     memset(h, -1, sizeof h);
//     construct(post, 0, n - 1, in, 0, n - 1, -1);

//     hh = 0, tt = -1;
//     q[++tt] = post[n - 1];
//     while (hh <= tt) {
//         int t = q[hh++];
//         for (int i = h[t]; ~i; i = ne[i]) q[++tt] = e[i];
//     }
//     for (int i = 0; i < hh; ++i)
//         if (!i) cout << q[i];
//         else cout << ' ' << q[i];
//     cout << endl;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     solve();
//     return 0;
// }

// 我写的逻辑和AC代码的逻辑其实是一样的，对于给定区间，首先找到根节点，然后分别构建左子树和右子树
// 不过对于一些数据的获取方法，我没有想到预处理和直接计算的方法，愚蠢的去一个个找，可能就是因为这个原因导致的段错误
// 需要注意在预处理某个数在中序遍历中的位置时不能用数组下标，因为题目中并未说明树中节点数的范围，数组下标没法定大小，需要用哈希表
// 二叉树的建立可以采用建图的方式；由于二叉树一个节点下最多仅有两个子节点，所以也可以采用数组进行存储，由于本题并未说明节点值范围，所以不能使用数组下标，采用哈希表
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>

using namespace std;

constexpr int N = 40;
constexpr int INF = 0x3f3f3f3f;

int n;
int post[N], in[N];
unordered_map<int, int> l, r, pos; // l[root]:root点的左节点，r[root]：root点的右节点， pos[val]：预处理val在中序遍历中的位置，避免在build过程中还需要遍历去寻找
int q[N], hh, tt;

// inorder_left, inorder_right, postorder_left, postorder_right
// 返回根节点
int build(int il, int ir, int pl, int pr) {
    int root = post[pr];
    int rootPos = pos[root];
    // 有无左右子树应当根据中序遍历进行判断
    if (il < rootPos) l[root] = build(il, rootPos - 1, pl, pl + rootPos - 1 - il); // 左子树
    if (ir > rootPos) r[root] = build(rootPos + 1, ir, pl + rootPos - 1 - il + 1, pr - 1); // 右子树
    return root;
}
void bfs(int root) {
    hh = 0, tt = -1;
    q[++tt] = root;
    while (hh <= tt) {
        int t = q[hh++];
        if (l.count(t)) q[++tt] = l[t];
        if (r.count(t)) q[++tt] = r[t];
    }

    for (int i = 0; i < hh; ++i)
        if (!i) cout << q[i];
        else cout << ' ' << q[i];
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> post[i];
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        pos[in[i]] = i;
    }

    int root = build(0, n - 1, 0, n - 1);
    bfs(root);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}