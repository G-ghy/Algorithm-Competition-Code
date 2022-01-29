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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;

// 看到maxID−minID+1这一刻，就反应到了这是区间元素个数
// 查看数据范围元素个数是1e5级别的，所以想到了二分
// 注：通过上面这两个性质就想到二分，本质上来说很离谱，只不过是经验罢了
// 二分显然是二分要进行修改的区间长度
// 我就想到了这里，然后发现对于给定的区间长度，我不知道如何判定
// 反思一下，我不知道如何判定的原因是思考方向出现了偏差，
// 我把问题的关注点始终放在了不同方向对于横坐标和纵坐标各自的贡献值上，然后进入了死胡同，
// 其实到这个时候，我自己应当做什么已经不明确了，只是说这个方向不知道怎么走了，
// 现在来看，当我的思维无法解决问题时，我要预估一下我无法继续前进是因为解题思路错误，还是说在这个思路下有些问题不知道怎么解决
// 按照一般经验来看，如果我的思考方向正确，每一步都应当有着明确的任务目标导向，而不是陷入到一个问题中甚至迷失了终极目标
// 我相信这是有感觉的，这个时候我应该跳出来重新审视一下解题思路，
// 正确的思路流程是，当我们想到二分修改长度时
// 下一步要想的应当是在区间中去枚举这段长度的一个区间，这是o(n)的过程
// 二分是o(logn)的，合在一起就是o(nlogn)，看到这个复杂度就应该知道这很像是正解
// 接下来要想的应当是，对于选定出来的这段区间，如何判断是否可以通过这段区间的指令使得机器人可以到达终点
// 换句话讲(假设选定的长度为len)，现在的问题就是能否可以通过修改某段指定长度为len的指令使得机器人到达终点(这一点总结使得这个步骤变得明确起来)
// 这个时候整段区间分成3部分，很重要的一点是这3部分的顺序并不重要，所以可以先做第1和第3部分，这时候到达一个点
// 需要以o(1)的时间计算先做第1部分和第3部分的结果，这里需要使用前缀和
// 不同的是这里既需要维护x方向的和，也要维护y方向的和
// 分析到这里，问题就变为能够通过修改某段指定长度为len的指令使得机器人从某点到达终点
// 每次前进要么是修改x方向的值，要么是修改y方向的值，因此从某点(x1, y1)到达终点(x2, y2)最少的次数step为abs(x1 - x2) + abs(y1 - y2)
// 所以条件1就是len >= step
// 上面的条件知道曼哈顿距离其实不难想的，困难的是下一个条件
// 这个条件及其容易被忽略，在没有听讲解之前我丝毫没有意识到这一点
// 当len > step时，剩下那些步骤要怎么走，那些步骤显然是必须要走的，因为它们是对应着指令的
// 通过step步就已经可以到达终点了，剩下步必须保证能够一去一回使得最终点不变
// 所以需要保证 (len - step)是偶数

int n;
char ins[N];
int ex, ey;
int sx[N], sy[N]; // 前缀和数组


bool inline check(int len) {
    for (int i = 1; i + len - 1 <= n; ++i) { // 枚举起点
        int j = i + len - 1; // 计算终点
        int x = sx[n] - (sx[j] - sx[i - 1]);
        int y = sy[n] - (sy[j] - sy[i - 1]);

        int d = abs(ex - x) + abs(ey - y); // 待走曼哈顿距离
        if (len >= d && !((len - d) % 2)) return true;
    }
    return false;
}
void solve() {
    cin >> n >> ins + 1 >> ex >> ey;

    // 预处理前缀和
    for (int i = 1; i <= n; ++i) {
        sx[i] = sx[i - 1], sy[i] = sy[i - 1];
        char dir = ins[i];
        if (dir == 'U') ++sy[i];
        else if (dir == 'D') --sy[i];
        else if (dir == 'R') ++sx[i];
        else --sx[i];
    }

    int res;
    if (n < abs(ex) + abs(ey) || (n - abs(ex) - abs(ey)) % 2) res = -1;
    else {
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        res = l;
    }

    cout << res << '\n';   
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}