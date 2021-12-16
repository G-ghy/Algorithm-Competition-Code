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
int postSeq[N], idx; // 后序遍历

int getTree(int l, int r) { // 根据先序遍历建树返回根节点
    if (l > r) return 0; // 节点编号从1开始，因此0代表空节点
    if (l == r) return l;

    int root = l;
    int type = node[l + 1].val >= node[l].val; // type==0:二叉搜索树； type==1：镜像

    // 仅需要根据根节点后面第一个元素和根节点的大小关系判断是二叉搜索还是镜像，至于是不是合法交由check完成
    int p;
    if (!type) {
        for (p = l + 1; p <= r; ++p)
            if (node[p].val >= node[root].val) break;
    } else {
        for (p = l + 1; p <= r; ++p)
            if (node[p].val < node[root].val) break;
    }
    node[root].l = getTree(l + 1, p - 1);
    node[root].r = getTree(p, r);
    return root;
}
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
pair<int, int> getMinMax(int u) { // 获取以u为根节点的子树中所有点权的最小值和最大值
    int minn = node[u].val, maxx = node[u].val;
    if (node[u].l) {
        auto ret = getMinMax(node[u].l);
        minn = min(minn, ret.first);
        maxx = max(maxx, ret.second);
    }
    if (node[u].r) {
        auto ret = getMinMax(node[u].r);
        minn = min(minn, ret.first);
        maxx = max(maxx, ret.second);
    }

    return {minn, maxx};
}
bool check(int u) {
    bool flag = true;
    if (node[u].l) {
        auto lret = getMinMax(node[u].l);
        // if (node[u].val <= lret.second) return false;
        if (!(node[u].val > lret.second)) return false;
        flag = check(node[u].l);
    }
    if (flag && node[u].r) {
        auto rret = getMinMax(node[u].r);
        // if (node[u].val > rret.first) return false;
        if (!(node[u].val <= rret.first)) return false;
        flag = check(node[u].r);
    }
    return flag;
}
bool checkMirror(int u) {
    bool flag = true;
    if (node[u].l) {
        auto lret = getMinMax(node[u].l);
        // if (node[u].val > lret.first) return false;
        if (!(node[u].val <= lret.first)) return false;
        flag = checkMirror(node[u].l);
    }
    if (flag && node[u].r) {
        auto rret = getMinMax(node[u].r);
        // if (node[u].val <= rret.second) return false;
        if (!(node[u].val > rret.second)) return false;
        flag = checkMirror(node[u].r);
    }
    return flag;
}
void getPostOrder(int u) { // 获取以u为根节点的子树的后序遍历
    if (node[u].l) getPostOrder(node[u].l);
    if (node[u].r) getPostOrder(node[u].r);
    postSeq[idx++] = node[u].val;
}
void output(int u) {
    cout << node[u].val << " l: " << node[node[u].l].val << " r: " << node[node[u].r].val << endl;;
    if (node[u].l) output(node[u].l);
    if (node[u].r) output(node[u].r);
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> node[i].val;

    int root = getTree(1, n);
    // output(root);
    if (check(root) || checkMirror(root)) {
        getPostOrder(root);
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
            if (!i) cout << postSeq[i];
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
