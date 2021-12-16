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

bool is_prime(int x) {
    if (x < 2) return true;
    for (int i = 2; i <= x / i; ++i)
        if (!(x % i)) return false;
    return true;
}
void solve() {
    int x;
    cin >> x;
    if (is_prime(x) && !(x & 1)) cout << "OK" << endl;
    else cout << "An invalid response was received from the upstream server" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}