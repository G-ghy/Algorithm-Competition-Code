/**
 * 本题容易出现两个问题
 * 1. 上来就考虑维护一个相等数据的并查集，一个不等数据的并查集
 *      这样做的问题是不等数据并查集没办法初始化
 *      我们的目的无非是判断两个数据是否同时具有相等和不等两种约束，只需要维护其中一个关系的集合，在遇到另一种关系时检查集合，由于不等关系的并查集无法维护，因此维护想等关系
 * 2. 注意题目中i和j的范围与n的范围不一样，第一次写没注意到这点，导致并查集初始化出现问题
 *      下边范围最大为1e9，直接遍历会超时，因此需要对数据进行离散化
 */
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

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

struct Constraint{
    int xi, xj, op;
} constraint[N];

unordered_map<int, int> p;

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a, b, op;
        cin >> a >> b >> op;
        constraint[i] = {a, b, op};
        p[a] = a; p[b] = b;
    }

    for (int i = 1; i <= n; ++i) {
        int a = constraint[i].xi, b = constraint[i].xj, op = constraint[i].op;
        if (op) {
            int pa = find(a), pb = find(b);
            if (pa != pb) p[pa] = pb;
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        int a = constraint[i].xi, b = constraint[i].xj, op = constraint[i].op;
        if (!op) {
            int pa = find(a), pb = find(b);
            if (pa == pb) {
                flag = false;
                break;
            }
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

// ep[1] = 1意味着1 == 1是正确的
// nep[1] = 1意味着1 != 1这不对呀，不管是现在的写法还是说把0和1的操作分开来看，对于nep的初始化问题一直都在
// 5
// 2
// 1 2 1
// 1 2 0
// 3
// 1 2 1
// 2 3 1
// 3 1 1
// 4
// 1 2 1
// 2 3 1
// 3 4 1
// 1 4 0
// 2
// 1 2 1
// 2 1 1
// 1
// 1 1 1

// output:
// NO
// YES
// NO
// YES
// NO

// right:
// NO
// YES
// NO
// YES
// YES