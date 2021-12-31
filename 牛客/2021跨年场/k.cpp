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

constexpr int N = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;

int cnt[N][28];
int res[N];

void solve() {
    int n;
    cin >> n;
    string str = "happynewyear";
    int len = str.size();
    
    for (int i = 0; i < len * n; ++i)
        ++cnt[i % n][str[i % len] - 'a'];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 26; ++j)
            res[i] += cnt[i][j] / 2;
    
    int maxx = -1;
    for (int i = 0; i < n; ++i)
        if (maxx == -1 || res[maxx] < res[i]) maxx = i;
    
    cout << maxx + 1 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}