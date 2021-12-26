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

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

void solve() {
    string a, s;
    cin >> a >> s;

    string tmp = "";
    if ((int)a.size() < (int)s.size()) {
        for (int i = 0; i < (int)s.size() - (int)a.size(); ++i) tmp += "0";
        tmp += a;
        a = tmp;
    }

    vector<int> res;
    int i = (int)a.size() - 1, j = (int)s.size() - 1;
    
    while (j >= 0) {
        string a_num = a.substr(i, 1);
        string s_num = s.substr(j, 1);
        if (s[j] < a[i]) {
            --j;
            if (j < 0) {
                cout << -1 << endl;
                return;
            }
            s_num = s.substr(j, 2);
        }
        if (stoi(s_num) - stoi(a_num) >= 10) {
            cout << -1 << endl;
            return;
        }
        res.push_back(stoi(s_num) - stoi(a_num));
        -- i; --j;
    }
    string b = "";
    for (int i = (int)res.size() - 1; ~i; --i) b += to_string(res[i]);
    int p;
    for (p = 0; p < (int)b.size() - 1; ++p)
        if (b[p] != '0') break;
    b = b.substr(p);
    
    if (i >= 0) {
        bool flag =  true;
        for (int k = 0; k <= i; ++k)
            if (a[k] != '0') {
                flag = false;
                break;
            }
        if (flag) cout << b << endl;
        else cout << -1 << endl;
    }
    else {
        cout << b << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}