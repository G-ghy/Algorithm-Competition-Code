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

int n;
vector<pair<int, int>> p; // <攻击力， 血量>

bool check(int inx, int sum) {
    int atk = p[inx].first;
    int hp = p[inx].second;
    double x = (sum - atk * hp) / (atk + 1);

    return (x > hp && x < 2 * hp);
}
void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int atk, hp;
        cin >> atk >> hp;
        sum += atk * hp;
        p.emplace_back(atk, hp);
    }

    bool flag = false;
    for (int i = 0; i < n; ++i)
        if (check(i, sum)) {
            flag = true;
            break;
        }
    
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}
// void solve2() {
//     cin >> n;
//     for (int i = 0; i < n; ++i) {
//         int atk, hp;
//         cin >> atk >> hp;
//         a.emplace_back(atk, hp);
//     }

//     sort(a.begin(), a.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
//         // if (a.second != b.second) return a.second > b.second;
//         // return a.first > b.first;
//         return (a.first + a.second) > (b.first + b.second);
//     });

//     // for (auto i : a) cout << i.first << ' ' << i.second << endl;
//     // cout << "----------------------" << endl;

//     // b = vector<pair<int, int>>(a.begin() + 1, a.end());
//     // sort(b.begin(), b.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
//     //     if (a.first != b.first) return a.first < b.first;
//     //     return a.second < b.second;
//     // });

//     // for (auto i : b) cout << i.first << ' ' << i.second << endl;
//     // cout << "----------------------" << endl;

//     int inx;
//     int atk = a[0].first, hp = a[0].second;
//     for (inx = 1; inx < n && hp > 0; ++inx) {
//         int k = max((b[inx].second + 1) / atk, 1);
//         hp -= k * b[inx].first;
//     }

//     if (inx == n && hp <= 0) cout << "YES" << endl;
//     else cout << "NO" << endl;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// 感觉会是排序，但是想不出排序规则
// 如果攻击力和生命值两个变量没法搞，有无可能是确定一个值讨论另一个，之前也有过这样的题目
// 考虑采用数学公式，但是满足条件的那个随从的条件没有列出来，总是缺少条件