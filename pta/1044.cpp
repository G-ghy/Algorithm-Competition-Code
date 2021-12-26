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

int n, m;
int f[N];
vector<pair<int, int>> res, greaterRes;

void solve() {
    cin >> n >> m;
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
        f[i] += f[i - 1];
    }
    for (int i = 1; i <= n; ++i)
        if (f[i] >= m) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (f[mid] <= f[i] - m) l = mid;
                else r = mid - 1;
            }
            if (f[i] - f[l] == m) res.emplace_back(l + 1, i);
            else if (f[i] - f[l] > m) {
                // 题目的意思是即使是非法情况，这个值也应该是相等且最小的，而非把所有非法情况全部输出
                // 最开始忽略了这一点，直接把所有非法情况全部输出了
                // 想到这一错误的原因是，在acwing上测试错误输出比标准输出多了一些东西，考虑这些东西到底是合法值还是非法值
                // 考虑如果是非法值为什么会多一些东西？这样想到了所有非法情况全部都输出了，所以会多一些东西
                // 在没有错误数据时，应该分别去想合法情况对不对，非法情况对不对，而不应该仅局限于代码的是否发生错误
                if (greaterRes.size() && f[greaterRes[0].second] - f[greaterRes[0].first - 1] < f[i] - f[l]) continue;
                if (greaterRes.size() && f[greaterRes[0].second] - f[greaterRes[0].first - 1] > f[i] - f[l]) greaterRes.clear();
                greaterRes.emplace_back(l + 1, i);
            }
        }

    sort(res.begin(), res.end());
    sort(greaterRes.begin(), greaterRes.end());

    if (res.size()) {
        for (auto point : res) 
            cout << point.first << "-" << point.second << endl;
    } else {
        for (auto point : greaterRes)
            cout << point.first << "-" << point.second << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}