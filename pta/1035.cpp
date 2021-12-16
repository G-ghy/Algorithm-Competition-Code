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
vector<string> res;

inline bool check(string &str) { // 返回是否出现模糊字符并进行修改
    bool flag = false;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] == '1' || str[i] == '0' || str[i] == 'l' || str[i] == 'O') {
            flag = true;
            switch (str[i]) {
                case '1': str[i] = '@'; break;
                case '0': str[i] = '%'; break;
                case 'l': str[i] = 'L'; break;
                case 'O': str[i] = 'o'; break;
            }
        }
    return flag;
}
void solve() {
    int n;
    bool flag = false;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string user, passwd;
        cin >> user >> passwd;
        flag = check(passwd);
        if (flag) res.push_back(user + " " + passwd);
    }
    if (flag) {
        cout << res.size() << endl;
        for (string str : res) cout << str << endl;
        return;
    }
    if (n == 1) cout << "There is " + to_string(n) + " account and no account is modified" << endl;
    else cout << "There are " + to_string(n) + " accounts and no account is modified" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}