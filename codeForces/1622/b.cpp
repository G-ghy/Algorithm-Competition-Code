// 所有喜欢的要比不喜欢的分值高 且 保证新分值与旧分值的差值和最小
// 把对应位置是0和1的都分别提取出来，把是0的依次分配为较小部分的值，是1的依次分配为较大部分的值

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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;
int res[N];

int n;
int p[N];
int q[N];
vector<pair<int, int>> big; // 1
vector<pair<int, int>> small; // 0

void solve() {
    big.clear();
    small.clear();

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i];
    string s;
    cin >> s;

    for (int i = 0; i < (int)s.size(); ++i)
        if (s[i] == '0') small.emplace_back(p[i], i);
        else big.emplace_back(p[i], i);

    sort(big.begin(), big.end());
    sort(small.begin(), small.end());

    for (int i = 0; i < (int)small.size(); ++i) {
        int pos = small[i].second;
        res[pos] = i + 1;
    }
    for (int i = 0; i < (int)big.size(); ++i) {
        int pos = big[i].second;
        res[pos] = (int)small.size() + i + 1;
    }

    for (int i = 0; i < n; ++i) cout << res[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}