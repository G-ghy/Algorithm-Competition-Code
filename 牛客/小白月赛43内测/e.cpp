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
#include <fstream>

using namespace std;

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

inline bool check(int x) {
    bool flag = true;
    while (x) {
        int c = x % 10;
        if (c != 1 && c != 2) {
            flag = false;
            break;
        }
        x /= 10;
    }

    return flag;
}
void solve() {
    // ofstream o;
    // o.open("out.txt", ios::out);

    int cnt = 0;
    for (int i = 0; i <= 1000000; ++i)
        // if (!(i % 3)) o << i << ' ' << i / 3 << '\n';
        if (!(i % 3) && check(i)) cout << i << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}