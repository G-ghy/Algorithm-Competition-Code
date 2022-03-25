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

constexpr int N = 1e4 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int a[N];
priority_queue<int> heap;
unordered_map<int, pair<int, int>> h;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);

        
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}