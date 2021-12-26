// 按照给定序列的顺序选择原串中的元素，询问拼接后得到的串的最大长度
// 按照给定序列的顺序是指例如2 3 1 5 6，选择1之后就不能再选择3了，
// 同时在原串中是不能走回头路的，只能向后选择，比如走到某个位置时正在选择5，只能选择该位置之的元素，前面的5不能再选择
// 如果将给定序列看为一种递增关系，那么本题求解的实际为最长上升子序列,更准确地说应当为最长有序子序列
// 显然是道dp
// 状态表示：dp[i]:所有以颜色i结尾的子序列
// 属性：所有子序列长度最大值
// 状态计算(集合划分)：可以按照最后一位颜色的前一位进行划分，对于所有以颜色i结尾的子序列，它的前一位颜色可以为给定顺序该颜色及其以前的颜色(因此对于一个颜色我们需要直到给定顺序排在它前面的有什么，需要维护每个元素在给定顺序中的位置)

// 最长上升子序列其实可以看为一种特殊的最长有序子序列
// 最长上升子序列的状态表示也是最后一位结尾的子序列，属性也是最大值，集合划分其实也是前一位是什么，不同点在于最长上升子序列前一位可能的值是比当前值小的所有值，例如当前为3，前一位可能为0 1 2 3，最长有序子序列只是给定了一个顺序
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

constexpr int N = 210;
constexpr int INF = 0x3f3f3f3f;

int c[N], cinx[N]; // c：给定颜色顺序；cinx：一种颜色在给定顺序中的位置
int dp[N];

void solve() {
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
        cinx[c[i]] = i; // 记录颜色在给定顺序中的序号
    }

    int l;
    cin >> l;
    int res = -INF;
    for (int i = 0; i < l; ++i) {
        int x;
        cin >> x;

        // 对集合进行划分，枚举它前一位可能的颜色
        int maxx = -INF;
        for (int j = 0; j <= cinx[x]; ++j)
            maxx = max(maxx, dp[c[j]] + 1);
        dp[x] = maxx;
        res = max(res, maxx);
    }

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}