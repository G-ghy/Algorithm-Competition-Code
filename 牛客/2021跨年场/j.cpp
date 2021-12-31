// 一道找规律的题目
// 把g展开是完全正确的思路，最后总结出来的原理和规律的原理是完全相符的
// 我的问题在于一味想直接求出最终答案，实际上求出g(x)=1，2，... 9的x是并不困难的
// 但是我就总想着怎么直接到11
// 有些时候既然不能直接到达终点，不妨看看中间过程中会出现哪些情况
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
using LL = long long;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

inline bool check(int x) {
    string num = to_string(x);
    bool flag = true;

    for (int i = 0; i < 2; ++i) {
        int sum = 1;
        for (int i = 0; i < (int)num.size(); ++i) sum *= num[i] - '0';
        if (sum < 10) {
            flag = false;
            break;
        }
        num = to_string(sum);
    }

    return flag;
}
LL get(string num) {
    LL sum = 1;
    for (int i = 0; i < (int)num.size(); ++i) sum *= num[i] - '0';
    return sum;
}
void solve() {
    // for (int i = 1; i < 1000000000; ++i)
    //     if (check(i)) {
    //         cout << i << endl;
    //         break;
    //     }

    cout << "277777788888899" << endl;
    // string num = "9";
    // for (int i = 0; i < 20; ++i) {
    //     // cout << num << ' ' << num.size() << ' ' << get(num) << endl;
    //     if (check(stoi(num))) {
    //         cout << num << endl;
    //         break;
    //     }
    //     num += "9";
    // }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}