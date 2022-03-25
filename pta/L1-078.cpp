#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

constexpr int N = 40;

bool check(string str) {
    int n = str.length();
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'q') {
            string substr = str.substr(i, 7);
            if (substr == "qiandao") return false;
        } else if (str[i] == 'e') {
            string substr = str.substr(i, 4);
            if (substr == "easy") return false;
        }
    }
    return true;
}
void solve() {
    int n, m;
    string str, res;

    int cnt{0};
    cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, str);
        if (check(str)) {
            if (cnt == m) res = str;
            ++cnt;
        }
	}

    if (m >= cnt) cout << "Wo AK le\n";
    else cout << res << '\n';

    // 如何判断是否做完全部题目
    // m是已做完题目数量
    // 在输入字符串时可以计数当前题目编号cnt，当输入完成后，该计数器cnt表示全部题目数量
    // 已做完题目数量 和 全部数量的比较即可得知是否做完所有题目
    // m >= cnt: 做完，反之没做完
}
int main() {
    solve();
    return 0;
}