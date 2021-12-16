#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

inline int lowbit(int x) {
    return x & -x;
}
int solve(int x) {
    int flag = x & 1; // 1奇 0偶

    int cnt = 0; // 1的个数
    while (x) {
        x -= lowbit(x);
        ++cnt;
    }

    int res = 0;
    if (cnt & 1) { // 奇数个1
        if (flag) res += (cnt / 2 - 1) * 2 + cnt / 2 * 2 + ((cnt % 2 == 0) ? 0 : cnt % 2 + 2); // 奇数
        else res += cnt / 2 * 4 + cnt % 2 + 2; // 偶数
    } else { // 偶数个1
        if (!cnt) res = 0;
        else {
            ++res;
            --cnt;
            if (flag) res += (cnt / 2 - 1) * 2 + cnt / 2 * 2 + ((cnt % 2 == 0) ? 0 : cnt % 2 + 2); // 奇数
            else res += cnt / 2 * 4 + cnt % 2 + 2; // 偶数
        }
    }

    return res;
}
inline int count(int x) {
    int cnt = 0;
    while (x) {
        x -= lowbit(x);
        ++cnt;
    }
    return cnt;
}
int bf(int x) {
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
    return res;
}
int main() {
    for (int i = 1000000; i <= 10000000; ++i)
        if (solve(i) != bf(i)) {
            cout << i << ' ' << solve(i) << ' ' << bf(i) << endl;
            break;
        }
    return 0;
}