// 在else中就算不考虑如何组织那i组连续1和其余0的问题，从复杂度上来说实际是n^2的，根本就不符合数据要求
// 1e5要控制在nlogn以内
//
// 区间求和 + 多次查询，应该想到前缀和的
// 即只需要快速求解出长度=len的优秀字符串数量，<=len的字符串中优秀字符串数量= (<=len-1)的字符串中优秀字符串数量 + 当前长度字符串中优秀字符串数量
// 外层枚举长度len是o(n)的，需要想一个复杂度<=O(logn)的方法求解长度==len的字符串中优秀字符串的数量，即最终复杂度<=O(nlogn)
// 
// 其余对于多次查询，除非每次查询的复杂度都极低，否则应当是想到预处理出结果的，否则一定会超时
// 如果不考虑预处理前缀和这一步，可以发现此前我用组合数学计算的想法和正解在外层O(n)的循环上其实是一样的，区别在于
// 每次选定字符串长度时，如何计算等于该长度的字符串中优秀字符串的数量，以后在求解最值或统计方案数时如果没有复杂度较合适的方法，可以考虑一下DP
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;
using LL = long long;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = 1e9 + 7;

int k, l, r;
int fact[N], infact[N]; // fact：阶乘，infact：逆元
int f[N];

inline int qpow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}
// 预处理阶乘和逆元
void init2() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (LL)fact[i - 1] * i % MOD;
        infact[i] = qpow(fact[i], MOD - 2, MOD);
    }
}
inline int c(int a, int b) {
    if (a < b) return 1;
    return (LL)fact[a] * infact[b] % MOD * infact[a - b] % MOD;
}
void solve2() {
    cin >> l >> r;
    int res = 0;
    for (int len = l; len <= r; ++len) {
        // 要求连续1的个数>实际可操作字符串长度时不能做任何操作，即只能是全0，因此答案+1
        if (k > len) res = (res + 1) % MOD;
        // 设k个连续1的组数为i，
        else {
            for (int i = 0; i <= len / k; ++i) {
                // 不管是把剩余元素向已有组中插入，还是把已有组向剩余元素中插入，都意味着插入的元素之间一定是分离的，可以并不需要它们分离
                // 组数确定后，剩余元素每个元素的可选位置种类为(组数+1)，这样算又有重复
                cout << i << ' ' << qpow(i + 1, len - k * i, MOD) << endl;
                res = (res + qpow(i + 1, len - k * i, MOD)) % MOD;
                // cout << i << ' ' << c(i + 1, len - k * i) << endl;
                // cout << i << ' ' << c(len - k * i + 1, i) << endl;
                // res = (res + c(i + 1, len - k * i)) % MOD;
                // res = (res + c(len - k * i + 1, i)) % MOD;
            }
            cout << endl;
        }
    }

    cout << res << endl;
}

void init() {
    memset(f, 0, sizeof f);

    f[0] = 1; // 此处的边界没有实际意义，仅保证后续数据的计算正确即可
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1];
        if (i >= k) f[i] = (f[i] + f[i - k]) % MOD;
    }
    for (int i = 1; i < N; ++i)
        f[i] = (f[i] + f[i - 1]) % MOD;
}
// 本题采用DP的状态表示和集合含义并不难想，难的在于如何对集合进行划分
// 状态表示：f[i] : 长度为i的字符串中优秀串的集合，维护属性为数量
// 分类方法：
// 考虑之前状态和当前状态的关联，之前状态是f[i-1]，即长度为i-1的字符串中优秀串的数量，当前状态为f[i]，即长度为i的字符串中优秀串的数量
// 两者相差的就是第i个字符，而第i个字符只有0和1两种情况，那么正常情况下应当考虑能够按照最后一位为0和1进行划分
// 假设最后一位为0，由于仅是对连续的k个1进行操作，所以最后的0不会成为被操作对象，因此此时f[i] == f[i - 1]
// 假设最后一位为1，由于仅是对连续的k个1进行操作，而f[i]代表的集合是优秀串，所以集合中所有串都应当满足最后k均为1
// 即最后k位为1，前面i-k位随意，此时的f[i] == f[i - k]
// 最后答案为f[i] = f[i - 1] + f[i - k], 将i从l遍历到r即可
void solve() {
    cin >> l >> r;
    cout << ((f[r] - f[l - 1] + MOD) % MOD) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T >> k;
    init();
    while (T--) solve();
    return 0;
}