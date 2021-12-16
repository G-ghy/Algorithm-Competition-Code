#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

// 10进制x转换为d进制，返回vector
inline vector<int> change(int x, int d) {
    vector<int> res;

    while (x) {
        res.push_back(x % d);
        x /= d;
    }
    return res;
}
// 对于给定vector判定是否为回文数
inline bool check(vector<int> &num) {
    int n = num.size();
    for (int i = 0; i < n / 2; ++i)
        if (num[i] != num[n - 1 - i]) return false;
    return true;
} 
void solve() {
    int n, b;
    cin >> n >> b;
    vector<int> num = change(n, b);
    
    if (check(num)) cout << "Yes" << endl;
    else cout << "No" << endl;
    for (int i = (int)num.size() - 1; ~i; --i)
        if (i == (int)num.size() - 1) cout << num[i];
        else cout << ' ' << num[i];
    cout << endl; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}