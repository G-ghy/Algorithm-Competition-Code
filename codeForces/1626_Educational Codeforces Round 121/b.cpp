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

constexpr int N = 2e5 + 10;
constexpr int INF = 0x3f3f3f3f;


inline int get(char a, char b) {
    int res = 0;
    res += (a - '0') + (b - '0');
    return res;
}
inline int transform(char a, char b) {
    int res = 0;
    res += (a - '0') * 10 + (b - '0');
    return res;
}
inline int getLen(int x) {
    if (x >= 10) return 2;
    return 1;
}
void solve() {
    string num;
    cin >> num;

    bool flag2 = false;
    int pos2Min = -1, pos2Max = -1;
    int pos1Min = -1, pos1Max = -1;

    for (int i = 0; i < (int)num.size() - 1; ++i) {
        int pre = transform(num[i], num[i + 1]);
        int now = get(num[i], num[i + 1]);
        if (getLen(now) == 2) {
            flag2 = true;
            pos2Min = i;
            if (now >= pre) {
                pos2Max = i;
                break;
            }
        }
    }
    
    string res = "";
    if (flag2) {
        if (pos2Max != -1) { // 存在两位数>原有值得情况
            res += num.substr(0, pos2Max);
            res += to_string(get(num[pos2Max], num[pos2Max + 1]));
            res += num.substr(pos2Max + 2);
        } else { // 不存在两位数>原有值，但是选择生成两位数一定比生成一位数更优，且所有生成得两位数都小于原有值，前面都保留，选择最后的会使得结果更大
            res += num.substr(0, pos2Min);
            res += to_string(get(num[pos2Min], num[pos2Min + 1]));
            res += num.substr(pos2Min + 2);
        }
    } else { // 因为不存在相加为2位数的情况，相邻两位的和一定会比之前的前一位要大，越靠前大会使得结果越大
        res += to_string(get(num[0], num[1]));
        res += num.substr(2);
    }

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}