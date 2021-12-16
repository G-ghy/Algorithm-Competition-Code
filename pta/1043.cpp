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

constexpr int N = 1010, M = N * N;
constexpr int INF = 0x3f3f3f3f;

// 给定一棵二叉搜索树(或其镜像)的先序遍历(不确定是不是合法的二叉搜索树)，但是仍然按照二叉搜索树的规则
// 把树还原(因为二叉搜索树的先序遍历是有规律的，因此仅根据先序遍历可以还原)
// 然后判断是否为合法的二叉搜索树即可
// 如果为合法的，需要输出现在这棵树的后序遍历(镜像就输出镜像的，没说一定要还原)
struct Node {
    int val, l, r;
} node[N];
int n;
int preSeq[N], postSeq[N], idx; // 后序遍历

// int getTree(int l, int r) { // 根据先序遍历建树返回根节点
//     if (l > r) return 0; // 节点编号从1开始，因此0代表空节点
//     if (l == r) return l;

//     int root = l;
//     int type = node[l + 1].val >= node[l].val; // type==0:二叉搜索树； type==1：镜像

//     // 仅需要根据根节点后面第一个元素和根节点的大小关系判断是二叉搜索还是镜像，至于是不是合法交由check完成
//     int p;
//     if (!type) {
//         for (p = l + 1; p <= r; ++p)
//             if (node[p].val >= node[root].val) break;
//     } else {
//         for (p = l + 1; p <= r; ++p)
//             if (node[p].val < node[root].val) break;
//     }
//     node[root].l = getTree(l + 1, p - 1);
//     node[root].r = getTree(p, r);
//     return root;
// }
// 错误原因在于只能够判断根节点和其所有子节点的大小关系是否合法，不能判断根节点和左右子树的所有节点是否合法
// bool check(int u) { // 判断以u为根节点的子树是否为合法的二叉搜索树,左小右大于等于
//     if (node[u].l && node[node[u].l].val >= node[u].val) return false;
//     if (node[u].r && node[node[u].r].val < node[u].val) return false;
    
//     bool flag = true;
//     if (node[u].l) flag = check(node[u].l);
//     if (flag && node[u].r) flag = check(node[u].r);

//     return flag;
// }
// bool checkMirror(int u) { // 判断以u为根节点的子树是否为合法的二叉搜索树的镜像
//     if (node[u].l && node[node[u].l].val < node[u].val) return false;
//     if (node[u].r && node[node[u].r].val >= node[u].val) return false;
    
//     bool flag = true;
//     if (node[u].l) flag = checkMirror(node[u].l);
//     if (flag && node[u].r) flag = checkMirror(node[u].r);

//     return flag;
// }
// pair<int, int> getMinMax(int u) { // 获取以u为根节点的子树中所有点权的最小值和最大值
//     int minn = node[u].val, maxx = node[u].val;
//     if (node[u].l) {
//         auto ret = getMinMax(node[u].l);
//         minn = min(minn, ret.first);
//         maxx = max(maxx, ret.second);
//     }
//     if (node[u].r) {
//         auto ret = getMinMax(node[u].r);
//         minn = min(minn, ret.first);
//         maxx = max(maxx, ret.second);
//     }

//     return {minn, maxx};
// }
// bool check(int u) {
//     bool flag = true;
//     if (node[u].l) {
//         auto lret = getMinMax(node[u].l);
//         // if (node[u].val <= lret.second) return false;
//         if (!(node[u].val > lret.second)) return false;
//         flag = check(node[u].l);
//     }
//     if (flag && node[u].r) {
//         auto rret = getMinMax(node[u].r);
//         // if (node[u].val > rret.first) return false;
//         if (!(node[u].val <= rret.first)) return false;
//         flag = check(node[u].r);
//     }
//     return flag;
// }
// bool checkMirror(int u) {
//     bool flag = true;
//     if (node[u].l) {
//         auto lret = getMinMax(node[u].l);
//         // if (node[u].val > lret.first) return false;
//         if (!(node[u].val <= lret.first)) return false;
//         flag = checkMirror(node[u].l);
//     }
//     if (flag && node[u].r) {
//         auto rret = getMinMax(node[u].r);
//         // if (node[u].val <= rret.second) return false;
//         if (!(node[u].val > rret.second)) return false;
//         flag = checkMirror(node[u].r);
//     }
//     return flag;
// }
// void getPostOrder(int u) { // 获取以u为根节点的子树的后序遍历
//     if (node[u].l) getPostOrder(node[u].l);
//     if (node[u].r) getPostOrder(node[u].r);
//     postSeq[idx++] = node[u].val;
// }
// void output(int u) {
//     cout << node[u].val << " l: " << node[node[u].l].val << " r: " << node[node[u].r].val << endl;;
//     if (node[u].l) output(node[u].l);
//     if (node[u].r) output(node[u].r);
// }
// void solve2() {
//     cin >> n;
//     for (int i = 1; i <= n; ++i) cin >> node[i].val;

//     int root = getTree(1, n);
//     output(root);
//     if (check(root) || checkMirror(root)) {
//         getPostOrder(root);
//         cout << "YES" << endl;
//         for (int i = 0; i < n; ++i)
//             if (!i) cout << postSeq[i];
//             else cout << ' ' << postSeq[i];
//         cout << endl;
//     }
//     else cout << "NO" << endl;
// }
// 判断的顺序恰好是左右，恰好可以按照这个顺序构造出后序遍历的结果
bool check(int l, int r, bool type) { // !type:二叉搜索树 type:镜像二叉搜索树
    // l == r时还要加点，不能return
    if (l > r) return true;
    int root = preSeq[l];
    if (!type) {
        int p;
        for (p = l + 1; p <= r; ++p)
            if (preSeq[p] >= root) break;
        for (int i = p; i <= r; ++i)
            if (preSeq[i] < root) return false;
        
        if (!check(l + 1, p - 1, type)) return false;
        if (!check(p, r, type)) return false;
    } else {
        int p;
        for (p = l + 1; p <= r; ++p)
            if (preSeq[p] < root) break;
        for (int i = p; i <= r; ++i)
            if (preSeq[i] >= root) return false;
        
        if (!check(l + 1, p - 1, type)) return false;
        if (!check(p, r, type)) return false;
    }
    postSeq[++idx] = root;
    return true;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> preSeq[i];

    bool flag = true;
    flag = check(1, n, 0); // 按照二叉搜索树判断一次 
    if (!flag) flag = check(1, n, 1); // 如果二叉搜索树无法满足再判断一次镜像二叉搜索树
    if (flag) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i)
            if (i == 1) cout << postSeq[i];
            else cout << ' ' << postSeq[i];
        cout << endl;
    }
    else cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// 由于先序遍历已经是根左右的顺序了，因此没必要把树的结构真的构造出来
// 我们只要能够判断左右子树的范围就可以判定序列是否合法
// 把结构构造出来确实心里会有底一些但是代码容易出错而且代码量较大
/**
 * 上述代码是错误的，对于下列数据
 * 3
 * 1 3 2
 * 上层递归解决3时，把其当作根节点1的镜像二叉搜索树的节点了，但是到3 2时，会把2当作3的二叉搜索树节点
 * 也就是说建立出来的树是既是二叉搜索树又是镜像二叉搜索树
 * 我的思维误区在于对于先序遍历1 2 3，我认定这一定是一棵镜像二叉搜索树，因为与1相邻的2比1大，所以它作为左子树就是镜像二叉搜索树了
 * 问题就出在这里，2 3为什么不能作为右子树呢？作为右子树就是二叉搜索树了
 * 所以对于一个先序遍历，究竟是二叉搜索树还是镜像二叉搜索树，应当是我们指定的
 * 所以最开始我就想错了，哎
 * 
 * 思路核心：并不需要真的建树，但是检查的过程实际和建树的顺序是一样的，先左子树再右子树，
 * 而这个顺序恰好和获取后序遍历的顺序是一样的
 */