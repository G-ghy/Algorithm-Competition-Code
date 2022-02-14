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

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

int n;
string num;
int f[N];
bool flag;
int sum;

// 思路不难想
// 第一段选择一个值
// 之后的段寻找合法的位置可以凑出值来
// 写完之后来看，易错点是对最后一段的处理方法
void dfs(int u, int start) {
    // 这里的特殊情况有 00200200 和 002000的情况
    // 第1种是最后一段全0，在第3段中找不到答案，但是可以归为第2段
    // 第2种是最后一段全0，但是如果仅按照第一段的分法不满足题目对于至少2段的要求
    // 这两个错误，不看数据很难想到，考试中大概率我是想不到的
    if ((f[n] - f[start - 1] == 0 && u >= 3) || start > n) {
        flag = true;
        return;
    }
    if (u == 1) {
        for (int i = 1; i <= n; ++i) {
            if (f[i] > f[n] - f[i - 1]) return; // 前 > 后
            sum = f[i];
            dfs(u + 1, i + 1);
        }
    } else {
        // 在start 到 n 中二分查找一个位置pos
        // pos满足 f[pos] - f[start - 1] == sum
        // 即寻找sum + f[start - 1]
        int l = start, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (f[mid] >= sum + f[start - 1]) r = mid;
            else l = mid + 1;
        }
        if (f[l] != sum + f[start - 1]) return;
        dfs(u + 1, l + 1);
    }
}
void solve() {
    cin >> n;
    cin >> num;

    for (int i = 0; i < n; ++i) {
        f[i + 1] = f[i] + (num[i] - '0');
    }

    flag = false;
    dfs(1, 1);

    cout << (flag ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// 另一种想法
// 把题目换个说法, 把一个序列分为k段, 满足这k段的和均相等, 问是否存在这样的k, 存在则输出YES, 不存在则输出NO
// 方法是去枚举k的值, k的值一定是能够整除序列的和的, 则可以计算出每段应该的和sum
// 之后对序列进行遍历, 同时进行计数, 如果一旦比sum大了, 则表示无法分为k段了; 如果等于sum, 则统计下一段的和
// 显然, 0的分法并不重要
// 枚举的思想非常关键, 题目本质是一个判定性问题，不是一个求解性问题，即并没有询问如何分段，只是问合法分段是否存在，
// 对于这种情况的题目，我们应当首先考虑“判定”, 而判定应当是对一种具体的情况进行判定, 所以就牵涉到枚举了
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

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

int f[N];

void solve() {
    int n;
    string num;
    cin >> n >> num;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        f[i] = num[i] - '0';
        sum += f[i];
    }

    // 在写完dfs之后再看这种方法，会怀疑最后一段能否正常处理
    // 例如020201最后的01可以判断出来非法吗？
    // 事实上，如果有这种想法，说明默认将前面每段的和想为2了
    // 可是，总和2+2+1==5又怎么会分成每段和为2的情况呢
    // 假设前面每段和为s都满足了，那么最后一段一定也是s，可以假设最后不是s，否则if (!(sum % k))就不会通过
    // 不过，这里并不是我希望你从这道题中得到经验的重点，重点在于那个枚举的思路
    // 平时做题很缺乏枚举这种想法
    bool flag = true;
    for (int k = 2; k <= n; ++k)
        if (!(sum % k)) {
            bool flag = true; // 每次判断k之前flag都应为true
            int s = sum / k;
            int t = 0;

            for (int i = 0; i < n; ++i) {
                t += f[i];
                if (t > s) { // 无法分为k段
                    flag = false;
                    break;
                }
                if (t == s) t = 0; // 进行下一段的求和
            }

            if (flag) {
                cout << "YES\n";
                return;
            }
        }
    
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}