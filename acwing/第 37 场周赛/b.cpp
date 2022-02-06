// 首先
// 1. 二分，需要数据满足>0
// 2. 哈希 通用性更强，不需要数据满足>0，从后向前枚举第一段的和，同时存储第3段的和，每次对于一个第一段的和，期望检查第三段中是否与第一段相等的值，直接检查哈希表即可
//    枚举顺序很重要，当我们枚举第一段时，要检查的第3段的情况处在后面一直到结尾，如果从前往后枚举第一段，在检查第3段时后面的数据是缺失的，无法比较
//    不过对于从后向前枚举这个事情，我们可能最初想的是这是可以更快得到答案的枚举顺序，未必会想到不同的顺序会使得结果错误
// 3. 双指针，需要数据满足>0
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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n;
LL d[N];
LL pre[N], ctn[N];

bool find(int start, LL val) {
    int l = start, r = n + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (ctn[mid] <= val) r = mid;
        else l = mid + 1;
    }
    
    if (ctn[l] == val) return true;
    return false;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];

    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + d[i];
    for (int i = n; ~i; --i) ctn[i] += ctn[i + 1] + d[i];

    int i;
    bool res = false;
    for (i = n; ~i; --i) {
        res = find(i + 1, pre[i]);
        if (res) break;
    }

    cout << pre[i] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}