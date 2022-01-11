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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

void solve() {
    string seq;
    stack<char> sta;

    cin >> seq;
    
    int res = 0;
    for (int i = 0; i < (int)seq.size(); ++i) {
        if (seq[i] == '(') sta.push(seq[i]);
        else {
            if (sta.size()) {
                res += 2;
                sta.pop();
            }
        }
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}