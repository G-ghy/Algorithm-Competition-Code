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

constexpr int N = 200010;
constexpr int INF = 0x3f3f3f3f;

int n;
int a[N], res[N], cnt;

// 选择删除序列中某值使得序列字典序最小
void solve() {
    int n;
    int max_pos = 0;
    cin >> n;
    for (int i = 0 ; i < n; ++i) {
        cin >> a[i];
        max_pos = (a[i] > a[max_pos]) ? i : max_pos;
    }

    int pos = -1;
    for (int i = 0; i < n - 1; ++i)
        if (a[i] > a[i + 1]) {
            pos = i;
            break;
        }
    
    pos = (pos == -1) ? max_pos : pos;
    
    for (int i = 0; i < n; ++i)
        if (a[i] != a[pos]) res[cnt++] = a[i];

    for (int i = 0; i < cnt; ++i) cout << res[i] << ' ';
    cout << '\n'; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}