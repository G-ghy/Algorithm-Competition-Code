#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

// constexpr int N = 

inline lowbit(int x) {
    return x & -x;
}
inline int count(int x) {
    int cnt = 0;
    while (x) {
        x -= lowbit(x);
        ++cnt;
    }
    return cnt;
}
void solve(int x) {
    int res = 0;
    while (x) {
        int cnt = count(x);
        if (cnt & 1) x ^= 1;
        else {
            int pos = 0;
            for (int i = 0; i < 30; ++i)
                if (x >> i & 1) pos = i;
            x ^= 1 << pos;
        }
        ++ res;
    }
    cout << res << endl;
}
int main() {
    for (int i = 1; i <= 20; ++i) {
        cout << i << ' ';
        solve(i);
    }
    return 0;
}