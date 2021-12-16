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

constexpr int N = 10;
constexpr int INF = 0x3f3f3f3f;

void solve() {
    string T = "oxxoxxoxxoxx";
    string S;
    
    bool flag = false;
    cin >> S;
    for (int i = 0; i < 3; ++i)
        if (S[0] == T[i]) {
            bool f = true;
            for (int j = 0, k = i; j < (int)S.size(); ++j, ++k)
                if (S[j] != T[k]) {
                    f = false;
                    break;
                }
            if (f) {
                flag = true;
                break;
            }
        }
    
    cout << (flag ? "Yes" : "No") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}