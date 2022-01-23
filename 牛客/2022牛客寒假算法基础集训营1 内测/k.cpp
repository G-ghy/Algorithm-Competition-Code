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
using LL = long long;

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

inline string getBin(int x) {
    string res = "";
    while (x) {
        res += (x & 1) + '0';
        x >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}
inline LL getVal(string snum) {
    LL res = 0, basic = 1;
    for (int i = (int)snum.size() - 1; ~i; --i) {
        if (snum[i] == '1') res += basic;
        basic *= 2;
    }
    return res;
}
// 想到了x加上x的倍数一定还是x的倍数
// 同时发现将x的二进制左移直接就是x的倍数
// 但是发现问题是如果两个二进制直接相加的结果就不一定是x的倍数了
// 这是因为两个二进制如果有交叉的部分相加会产生进制，结果就不一定是多少了
// 那么解决办法就是让它不产生交叉的部分，所以直接把二进制整体左移拼接到原二进制的左侧即可
// 既可以满足倍数，又可以满足子串的存在
void solve() {
    int x;
    cin >> x;
    // for (int i = 1; i <= 10000; ++i) {
    //     string bin = getBin(i);
    //     int val = getVal(bin + bin);
    //     if (val % i) {
    //         cout << i << '\n';
    //         cout << bin << '\n' << getBin(val) << '\n';
    //         cout << "---------------------------------\n";
    //     }
    // }
    string bin = getBin(x);
    cout << getVal(bin + bin) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}