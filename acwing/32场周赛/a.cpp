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

constexpr int N = 110;
constexpr int INF = 0x3f3f3f3f;

void solve() {
    string str;
    string res1 = "1111111";
    string res2 = "0000000";

    bool flag = false;
    cin >> str;
    for (int i = 0; i < (int)str.size(); ++i) {
        string subStr = str.substr(i, 7);
        if (subStr == res1 || subStr == res2) {
            flag = true;
            break;
        }
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}