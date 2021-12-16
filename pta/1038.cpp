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

constexpr int N = 1e4 + 10;
constexpr int INF = 0x3f3f3f3f;

int n;
string num[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> num[i];

    sort(num, num + n, [](string &a, string &b) -> bool {
        return a + b < b + a;
    });

    string res = "";
    for (int i = 0; i < n; ++i) res += num[i];
    
    // 处理前导0
    // 从res[0]~res[n-2]如果均为0，则最后一位不管是多少都应当输出
    int p;
    for (p = 0; p < res.size() - 1; ++p)
        if (res[p] != '0') break;
    res = res.substr(p);

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}