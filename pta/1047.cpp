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

constexpr int N = 2510, M = 40010;
constexpr int INF = 0x3f3f3f3f;

// vector<string> a[N];
// vector<char *> list[N];

// inline bool cmp(char *s1, char *s2) {   
//     for (int i = 0; i < 4; ++i)
//         if (s1[i] < s2[i]) return true;
//         else if (s1[i] > s2[i]) return false;
//     return true; // 相等
// }
// void solve() {
//     cin >> n >> m;
//     for (int i = 0; i < n; ++i) {
//         char name[5];
//         int c;
//         cin >> name >> c;
//         while (c--) {
//             int id;
//             cin >> id;
//             list[id].push_back(name);
//         }
//     }

//     for (int i = 1; i <= m; ++i) {
//         sort(list[i].begin(), list[i].end(), cmp);
//         cout << i << ' ' << (int)list[i].size() << endl;
//         // for (char *name : list[i]) cout << name << endl;
//         for (int j = 0; j < (int)list[i].size(); ++j) cout << list[i][j] << endl;
//     }
// }


// vector<int> slist[N]; // 课程学生名单
// string sname[M]; // 学生姓名

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < n; ++i) {
//         cin >> sname[i];
//         int c, id;
//         cin >> c;
//         while (c--) {
//             cin >> id;
//             slist[id].push_back(i);
//         }
//     }

//     for (int i = 1; i <= m; ++i) {
//         sort(slist[i].begin(), slist[i].end(), [](int inx1, int inx2) -> bool {
//             return sname[inx1] <= sname[inx2];
//         });
//         cout << i << ' ' << (int)slist[i].size() << endl;
//         for (int inx : slist[i]) cout << sname[inx] << endl;
//     }
// }

vector<string> slist[N];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        char tmp[5];
        int c;
        scanf("%s%d", &tmp, &c);
        while (c--) {
            int id;
            scanf("%d", &id);
            string name(tmp);
            slist[id].push_back(name);
        }
    }

    for (int i = 1; i <= m; ++i) {
        sort(slist[i].begin(), slist[i].end());
        printf("%d %d\n", i, (int)slist[i].size());
        for (string name : slist[i]) printf("%s\n", name.c_str());
    }
}

int main() {
    solve();
    return 0;
}