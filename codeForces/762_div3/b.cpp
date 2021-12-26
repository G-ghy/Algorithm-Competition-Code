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
#include <fstream>

using namespace std;
using LL = long long;

constexpr int N = 1e5;
constexpr int INF = 0x3f3f3f3f;


vector<LL> seq;
unordered_set<LL> st;

inline void init() {
    for (LL i = 1; i <= N; ++i) {
        if (!st.count(i * i)) {
            st.insert(i * i);
            seq.push_back(i * i);
        }
        if (!st.count(i * i * i)) {
            st.insert(i * i * i);
            seq.push_back(i * i * i);
        }
    }

    sort(seq.begin(), seq.end());
}
void solve() {
    int n;
    cin >> n;
    int l = 0, r = seq.size() - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (seq[mid] <= n) l = mid;
        else r = mid - 1;
    }
    cout << l + 1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}