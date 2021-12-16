// 打表，不过下面程序跑的实在太慢了，就一个k==2少说跑了5分钟，测试遇到这种题目最好一开始就跑上(确定正确的前提下)
// static constexpr long long ans[][30] = {
//     {1, 3, 5, 7, 9, 33, 99, 313, 585, 717, 7447, 9009, 15351, 32223, 39993, 53235, 53835, 73737, 585585, 1758571, 1934391, 1979791, 3129213, 5071705, 5259525, 5841485, 13500531, 719848917, 910373019, 939474939},
//     {1, 2, 4, 8, 121, 151, 212, 242, 484, 656, 757, 29092, 48884, 74647, 75457, 76267, 92929, 93739, 848848, 1521251, 2985892, 4022204, 4219124, 4251524, 4287824, 5737375, 7875787, 7949497, 27711772, 83155138},
//     {1, 2, 3, 5, 55, 373, 393, 666, 787, 939, 7997, 53235, 55255, 55655, 57675, 506605, 1801081, 2215122, 3826283, 3866683, 5051505, 5226225, 5259525, 5297925, 5614165, 5679765, 53822835, 623010326, 954656459, 51717171715},
//     {1, 2, 3, 4, 6, 88, 252, 282, 626, 676, 1221, 15751, 18881, 10088001, 10400401, 27711772, 30322303, 47633674, 65977956, 808656808, 831333138, 831868138, 836131638, 836181638, 2512882152, 2596886952, 2893553982, 6761551676, 12114741121, 12185058121},
//     {1, 2, 3, 4, 5, 7, 55, 111, 141, 191, 343, 434, 777, 868, 1441, 7667, 7777, 22022, 39893, 74647, 168861, 808808, 909909, 1867681, 3097903, 4232324, 4265624, 4298924, 4516154, 4565654},
//     {1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596, 9470749, 61255216, 230474032, 466828664, 485494584, 638828836, 657494756, 858474858, 25699499652, 40130703104, 45862226854, 61454945416, 64454545446},
//     {1, 2, 3, 4, 5, 6, 7, 9, 121, 292, 333, 373, 414, 585, 3663, 8778, 13131, 13331, 26462, 26662, 30103, 30303, 207702, 628826, 660066, 1496941, 1935391, 1970791, 4198914, 55366355},
//     {1, 2, 3, 4, 5, 6, 7, 8, 191, 282, 373, 464, 555, 646, 656, 6886, 25752, 27472, 42324, 50605, 626626, 1540451, 1713171, 1721271, 1828281, 1877781, 1885881, 2401042, 2434342, 2442442}
// };
// 错误的暴力方式，计算太慢了
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

// constexpr int N = 15;
// constexpr int INF = 0x3f3f3f3f;

// int res[N][40];

// string change(int num, int k) {
//     string res = "";
//     while (num) {
//         res += num % k + '0';
//         num /= k;
//     }
//     return res;
// }
// bool check(int num, int k) {
//     string origin = change(num, 10);
//     int n = origin.size();
//     if (origin[n - 1] == '0') return false;
//     for (int i = 0; i < n / 2; ++i)
//         if (origin[i] != origin[n - i - 1]) return false;

//     string after = change(num, k);
//     n = after.size();
//     if (after[n - 1] == '0') return false;
//     for (int i = 0; i < n / 2; ++i)
//         if (after[i] != after[n - i - 1]) return false;

//     return true;
// }
// void solve(int k) {
//     int cnt = 0;
//     for (int i = 1; cnt < 30; ++i) {
//         if (check(i, k)) res[k][cnt++] = i;
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     // for (int i = 2; i <= 9; ++i) solve(i);
//     int inx = 2;
//     solve(inx);
//     cout << "-------------------------" << endl;
//     for (int i = inx; i <= inx; ++i) {
//         cout << i << endl;
//         for (int j = 0; j < 30; ++j) cout << res[i][j] << ' ';
//         cout << endl << "--------------------------" << endl;
//     }
//     return 0;
// }

// 对于一个10进制数在k进制下是否为回文的，这一步操作是免不了的
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

vector<int> res;

void get_palindrome_number() {
    vector<int> res;
    // 每次获取[10^start, 10^start - 1)
    for (int start = 1; start <= 10; start *= 10) {
        // 除末尾位其余位取反拼接到原数末尾获得长度为2*len(start)+1的回文数
        for (int i = start; i <= start * 10 - 1; ++i) {
            int num = i;
            for (int j = i / 10; j; j /= 10) // 起始先/10将末尾位删除
                num = num * 10 + j % 10;
            res.push_back(num);
        }

        // 所有位取反拼接到原数末尾获得长度为2*len(start)+2的回文数
        for (int i = start; i <= start * 10 - 1; ++i) {
            int num = i;
            for (int j = i; j; j /= 10)
                num = num * 10 + j % 10;
            res.push_back(num);
        }
    }

    for (int num : res) 
        cout << num << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}