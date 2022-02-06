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
using LL = long long;

class Solution {
public:
    int qpow(int a, int b, int p) {
        int res = 1;
        while (b) {
            if (b & 1) res = 1ll * res * a % p;
            a = 1ll * a * a % p;
            b >>= 1;
        }
        return res;
    }
    LL exgcd(LL a, LL b, LL &x, LL &y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }
        int gcd = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return gcd;
    }
    string subStrHash(string s, int p, int mod, int len, int v) {
        int n = s.size();
        vector<LL> pre(n + 10, 0);
        
        LL basic = 1;
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1];
            pre[i] = (pre[i] + 1ll * (s[i - 1] - 'a' + 1) * basic % mod) % mod;
            basic = basic * p % mod;
        }
        
        int pos = 0;
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            // LL ni = qpow(qpow(p, mod - 2, mod), i - 1, mod);
            // 忘记了费马小定理求解逆元的条件是mod是素数
            LL ni, y;
            exgcd(p, mod, ni, y);
            ni = qpow(ni, i - 1, mod);
            if ((1ll * (pre[j] - pre[i - 1]) * ni % mod) % mod == v) {
                pos = i;
                break;
            }
        }
        
        cout << pos << endl;
        string res = "";
        for (int i = pos - 1; i <= pos - 1 + len - 1; ++i) res += s[i];

        return res;
    }
};

void solve() {
    Solution s;
    s.subStrHash("xxterzixjqrghqyeketqeynekvqhc", 15, 94, 4, 16);
    // s.subStrHash("leetcode", 7, 20, 2, 0);
    // s.subStrHash("fbxzaad", 31, 100, 3, 32);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}