// 以下代码并没有问题，可以ac，但是由于在比赛时思维比较混论导致代码实现比较不合理
// 问题的核心在于统计输入字符串中每个出现字符在字符串中两个字符之间的距离最大值，在所有最大值中取得最小值
// 计算距离，代码实现上可以通过直接计数器的方式，也可以通过两次坐标直接相减
// 而且，由于要考虑起始和结束位置对于每个字符来说都需要更新，所以如果采用计数器计算距离还需要反向跑一遍
// 但是通过下标运算，实现细节较少逻辑更为清晰更不容易出错
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <cmath>
// #include <unordered_map>
// #include <unordered_set>
// #include <set>

// using namespace std;

// constexpr int N = 30;
// constexpr int INF = 0x3f3f3f3f;

// int maxCnt[N], cnt[N];
// bool exist[N], st[N];
// vector<char> vec;

// void solve() {
//     memset(exist, 0, sizeof exist);
//     memset(st, 0, sizeof st);
//     memset(maxCnt, 0, sizeof maxCnt);
//     memset(cnt, 0, sizeof cnt);

//     string str;
//     cin >> str;
//     for (char ch : str) exist[ch - 'a'] = true;

//     for (int i = 0; i < 26; ++i) {
//         char c = i + 'a';
//         if (!exist[i] || st[i]) continue;
//         st[i] = true;

//         for (char ch : str) {
//             int inx = ch - 'a';
//             if (ch == c) {
//                 ++cnt[inx];
//                 if (cnt[inx] != 1) {
//                     maxCnt[inx] = max(maxCnt[inx], cnt[inx] - 1);
//                     cnt[inx] = 1;
//                 }
//             } else {
//                 if (cnt[c - 'a']) ++cnt[c - 'a'];
//             }
//         }
//     }

//     for (int i = 0; i < 26; ++i)
//         maxCnt[i] = max(maxCnt[i], cnt[i]);

//     memset(cnt, 0, sizeof cnt);
//     memset(st, 0, sizeof st);
//     for (int i = 0; i < 26; ++i) {
//         char c = i + 'a';
//         if (!exist[i] || st[i]) continue;
//         st[i] = true;

//         for (int i = (int)str.size() - 1; ~i; --i) {
//             char ch = str[i];
//             int inx = ch - 'a';
//             if (ch == c) {
//                 ++cnt[inx];
//                 if (cnt[inx] != 1) {
//                     maxCnt[inx] = max(maxCnt[inx], cnt[inx] - 1);
//                     cnt[inx] = 1;
//                 }
//             } else {
//                 if (cnt[c - 'a']) ++cnt[c - 'a'];
//             }
//         }
//     }

//     // 可能有些字母没有出现第2次
//     for (int i = 0; i < 26; ++i)
//         maxCnt[i] = max(maxCnt[i], cnt[i]);
    
//     int res = INF;
//     for (int i = 0; i < 26; ++i)
//         if (exist[i]) res = min(res, maxCnt[i]);

//     cout << res << endl;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     solve();
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

char str[N];
int last[N], d[N]; // last：字符上次出现的位置 d:对于当前字符维护的两个相同字符之间的最大距离

void solve() {
    // 字符串从1开始读入，0位置默认考虑为每个字符的初始位置，这样可以比较方便地计算第一个字符的距离
    // 对于结尾，把n+1位置考虑为每个字符的结束位置，这样可以比较方便地计算最后一个字符到结尾的距离
    memset(last, 0, sizeof last);

    cin >> (str + 1);
    int n = strlen(str + 1) - 1;

    for (int i = 1; i <= n; ++i) {
        int x = str[i] - 'a';
        d[x] = max(d[x], i - last[x]);
        last[x] = i;
    }

    // 此时last存储的已经是每个字符最后一个位置了
    // 再枚举仅需要枚举26个字符即可，不需要再枚举str了
    // 不需要考虑str中没出现的字符的d会是n+1，因为最后取的是所有d中的min，这些str中不存在的字符的d不会对答案产生影响
    for (int i = 0; i < 26; ++i)
        d[i] = max(d[i], n + 1 - last[i]);

    int res = n + 1;
    for (int i = 0; i < 26; ++i)
        res = min(res, d[i]);
    
    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}