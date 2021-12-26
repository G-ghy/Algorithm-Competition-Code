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

constexpr int N = 1e5 + 10, M = 1e7 + 10;
constexpr int INF = 0x3f3f3f3f;

inline bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i)
        if (x % i == 0) return false;
    return true;
}
inline string getbin(int x) {
    string res = "";
    while (x) {
        res += (x & 1) + '0';
        x >>= 1;
    }
    reverse(res.begin(), res.end());

    return res;
}

bool st[M];
int primes[N], cnt;

inline void get_primes(int x) {
    for (int i = 2; i <= x; ++i) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; ++j) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    int q;
    cin >> q;
    int res = 0;
    bool first = true;
    for (int i = 0; i < cnt; ++i) {
        if (first) {
            cout << q << " : " << getbin(q) << endl;
            first = false;
        }
            if ((q ^ primes[i]) < q) {
            ++res;
            cout << (q ^ primes[i]) << " : " << getbin(q ^ primes[i]) << endl;
        }
    }

    // cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    get_primes(1048576);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}