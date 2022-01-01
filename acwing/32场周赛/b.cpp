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

constexpr int N = 1010;
constexpr int INF = 0x3f3f3f3f;

int n;
int a[N][N];
int count[N];

inline void output() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
}
// 前期思路是非常正确的
// 由于同时存在行和列两个变化因素，所以考虑要固定一个因素
// 也就是先满足行上任意两数不同的要求
// 之后对于一行上面的数据任意交换，行都不受影响
// 这时候去考虑如何满足列的要求即可
// 想到这里都还是正确的
// 后面的难点在于怎么调整可以满足列上的要求，这里没有想出来
// 看正解需要加额外的行和列，理性来说这种方法此前不曾见过，大概率赛时是想不出来的
void solve() {
    cin >> n;

    int begin = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = begin, k = 0; k < n; ++j, ++k)
            a[i][k] = j % n;
        ++begin;
    }

    int pos = n - 1;
    for (int i = 1; i < n; ++i) {
        swap(a[i][i], a[i][pos--]);
    }

    output();

    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}