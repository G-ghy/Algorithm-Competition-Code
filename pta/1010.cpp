/**
 * 不管几进制，全部转换成10进制
 * 数字按字符串读入，方便处理a-z
 * 
 * 这道题的坑点还挺多的，在最初的想法中实际上是想错了，只想到了n2的radix下限值是最大数字+1，想当然的认为上限值是36(因为最大的数字是35)
 * 最大的可能合法上限值实际上是n1转换成10进制之后的值，因为如果大于这个值，那么n2转换为10进制就一定大于n1转换为10进制的值
 * n1转换为10进制之后的最大值是会爆int的，需要开long long，这点没想到
 * 如果线性扫描n2可能的radix，会超时，寻找数值线性扫描行不通，在没有规律时首先考虑二分，上下界上面已经分析出来了
 * 考虑是否可以将区间划分为具有不同性质的两段
 * 如果选定某个radix，导致n2转换为10进制之后的结果>n1，那么显然>该radix的值都不会是答案了，因为进制数越大，转换为10进制之后的结果越大
 * 因此可以采用二分
 */
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <cmath>

// using namespace std;

// constexpr int N = 15;

// int tag, radix;
// char n1[N], n2[N];
// int mapping[40];

// inline void maps() {
//     for (int i = 0; i <= 9; ++i) mapping[i] = i;
//     for (char ch = 'a'; ch <= 'z'; ++ch) mapping[ch - 'a' + 10] = ch - 'a' + 10;
// }
// // 将radix进制的长度为len的num转换为10进制的数
// int changeRadix(char num[], int len, int radix) {
//     int res = 0, basic = 1;
//     for (int i = len - 1; ~i; --i) {
//         if (num[i] >= '0' && num[i] <= '9') res += mapping[num[i] - '0'] * basic;
//         else res += mapping[num[i] - 'a' + 10] * basic;
//         basic *= radix;
//     }
//     return res;
// }
// void swap(char num1[], int len1, char num2[], int len2) {
//     char t[N];
//     memcpy(t, num1, len1);
//     memcpy(num1, num2, len2);
//     memcpy(num2, t, sizeof t);
// }
// void solve() {
//     cin >> n1 >> n2;
//     cin >> tag >> radix;
//     if (tag == 2) swap(n1, strlen(n1), n2, strlen(n2));

//     int n;
//     n = changeRadix(n1, strlen(n1), radix);

//     int res = 0;
//     int beginRadix = 0;
//     for (int i = 0; i < strlen(n2); ++i) {
//         if (n2[i] >= '0' && n2[i] <= '9') beginRadix = max(beginRadix, mapping[n2[i] - '0']);
//         else beginRadix = max(beginRadix, mapping[n2[i] - 'a' + 10]);
//     }
//     ++beginRadix;
//     for (int i = beginRadix; i <= 36; ++i)
//         if (changeRadix(n2, strlen(n2), i) == n) {
//             res = i;
//             break;
//         }
    
//     if (res) cout << res << endl;
//     else cout << "Impossible" << endl; 
// }
// int main() {
//     maps();
//     solve();
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
using LL = long long;

constexpr int N = 15;

LL tag, radix;
string n1, n2;
int mapping[40];

inline void maps() {
    for (int i = 0; i <= 9; ++i) mapping[i] = i;
    for (char ch = 'a'; ch <= 'z'; ++ch) mapping[ch - 'a' + 10] = ch - 'a' + 10;
}
// 将radix进制的长度为len的num转换为10进制的数
inline LL changeRadix(string &num, LL radix) {
    int len = num.size();
    LL res = 0, basic = 1;
    for (int i = len - 1; ~i; --i) {
        if (num[i] >= '0' && num[i] <= '9') res += mapping[num[i] - '0'] * basic;
        else res += mapping[num[i] - 'a' + 10] * basic;
        basic *= radix;
    }
    return res;
}
inline bool check(LL n, LL radix) {
    return changeRadix(n2, radix) >= n;
}
void solve() {
    cin >> n1 >> n2;
    cin >> tag >> radix;
    if (tag == 2) swap(n1, n2);

    LL n;
    n = changeRadix(n1, radix);

    int beginRadix = 0;
    for (int i = 0; i < n2.size(); ++i) {
        if (n2[i] >= '0' && n2[i] <= '9') beginRadix = max(beginRadix, mapping[n2[i] - '0']);
        else beginRadix = max(beginRadix, mapping[n2[i] - 'a' + 10]);
    }
    ++beginRadix;

    LL l = beginRadix, r = n;
    while (l < r) {
        LL mid = (l + r) / 2;
        if (check(n, mid) || changeRadix(n2, mid) < 0) r = mid;
        else l = mid + 1;
    }
    
    if (changeRadix(n2, l) == n) cout << l << endl;
    else cout << "Impossible" << endl;
}
int main() {
    maps();
    solve();
    return 0;
}