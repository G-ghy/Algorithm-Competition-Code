#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

void solve() {
    unordered_map<int, vector<int>> ma;
    vector<int> container;
    container.push_back(1);
    ma[1] = container;

    vector<int> &c = ma[1];
    for (int v : c) cout << v << ' ' ;
    cout << endl;
    c.push_back(2);
    for (int v : c) cout << v << ' ' ;
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}