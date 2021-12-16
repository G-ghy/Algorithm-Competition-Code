#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

inline bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i)
        if (!(x % i)) return false;
    return true;
}
int reverse_num(int x, int d) { // 把10进制的x转化为d进制数，翻转后转化为10进制
    // 把x转换成d进制
    string str = "";
    while (x) {
        str += x % d + '0';
        x /= d;
    }
    // 由于是逆序存储，所以此时的结果就是顺序strreverse的结果

    // 将reverse后的数值转化为10进制
    int res = 0;
    int basic = 1;
    for (int i = str.size() - 1; ~i; --i) {
        if (str[i] != '0') res += basic * (str[i] - '0');
        basic *= d;
    }

    return res;
}
void solve(int n, int d) {
    bool flag = is_prime(n);
    if (flag) flag = is_prime(reverse_num(n, d));

    cout << (flag ? "Yes" : "No") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, d;
    while (cin >> n, n >= 0) {
        cin >> d;
        solve(n, d);
    }
    return 0;
}