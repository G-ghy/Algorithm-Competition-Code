// 一定要想到把异或操作和与或操作分离开
// 很明显能看出不能去模拟过程，最开始想找规律迭代之类的，但是没想出用什么结构去实现，通过尝试一组数据发现最后结果都不重复，然后发现了结果和操作串之间的联系
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

void solve() {
    int n;
    string op;
    cin >> n;
    
    // 好蠢啊，居然因为这个多提交一次多了罚时，真的蠢
    if (!n) {
        cout << "0" << endl;
        return;
    }

    cin >> op;
    int cnt = 0, pos = -1;
    for (int i = 0; i < n; ++i)
        if (op[i] == '2') {
            if (pos == -1) pos = i;
            ++cnt;
        }
    
    string res = "";
    if (cnt > 1) res = "0";
    else if (cnt == 1) {
        res += "1";
        for (int i = 0; i < pos; ++i) res += "0";
    } else {
        while (op.size() > 1 && op.back() == '0') op.pop_back();
        reverse(op.begin(), op.end());
        res = op;
    }

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}