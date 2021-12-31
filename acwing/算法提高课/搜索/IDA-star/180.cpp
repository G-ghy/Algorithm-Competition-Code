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

constexpr int N = 20;
constexpr int INF = 0x3f3f3f3f;

int n;
int a[N];
int t[10][N];

inline int f() { // 计算估价函数
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i)
        if (a[i] != a[i + 1] - 1) ++cnt;
    
    return (cnt + 2) / 3;
}
bool dfs(int depth, int max_depth) { // 当前已经操作depth步，最大操作max_depth步
    if (!f()) return true; // 估价值为0时已经到达目标状态
    if (depth + f() > max_depth) return false; // 如果当前还没有到达终点并且当前搜索层数加上剩余估计待搜索层数已经超过限定值则直接返回

    for (int len = 1; len <= n; ++len) // 枚举连续区间的长度
        for (int l = 0; l + len - 1 < n; ++l) { // 枚举连续区间起点
            int r = l + len - 1;
            // 将序列[l, r]变动位置
            // 对于1 2 3 4 5 6，将4 5放到2前面<=>将2 3放到5后面，即后面序列在移动位置时，目标位置只需要考虑该序列后面的
            for (int k = r + 1; k < n; ++k) { // 依次考虑将[l, r]放置到a[k]...a[n]的后面
                // 本次移动后，下次需要恢复现场，因此需要辅助数组
                // 此时需要考虑此时进行的是递归操作，是否每层都需要开辅助数组，不同层之间是否会相互影响。显然是有影响的，当前层的搜索状态在进入到下层搜索时不应当被修改
                memcpy(t[depth], a, sizeof a);
                // 把[l, r]放置到a[k]的后面
                for (int x = r + 1, y = l; x <= k; ++x, ++y) a[y] = t[depth][x]; // [r + 1, k] -> [l, k-r-1+l]
                for (int x = l, y = k - r + l; x <= r; ++x, ++y) a[y] = t[depth][x]; // [l, r] -> [k-r+l, k]
                if (dfs(depth + 1, max_depth)) return true;
                memcpy(a, t[depth], sizeof a);
            }
        }
    
    return false;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    // int depth = 1; // 初始限制只能操作1步
    int depth = 0; // 在搜索到目标序列返回时采用depth作为答案，因此它除了限制的最大深度的含义外应当还有操作步数这一含义，初始值为0
    // depth==0时表示此时已经操作0步，等于4时表示已经操作4步，在>=5时才需要停止
    while (depth < 5 && !dfs(0, depth)) ++depth;

    if (depth == 5) cout << "5 or more" << endl;
    else cout << depth << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();

    
    return 0;
}