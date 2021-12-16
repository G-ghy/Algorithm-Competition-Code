/**
 * 各种数据结构例如pair的使用没什么好说的，需要什么用什么就ok了
 * 按照优先级维护A，C，M，E四个成绩列表也没什么不好想的
 * 最好的想法是维护每个同学的最优次序，在每个成绩列表中对这个次序进行更新，一方面按照给定给的成立列表顺序可以保证题目中对于ACME优先级的要求，同时还能以较低的复杂度维护出答案
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using PII = pair<int, int>;
using PIC = pair<int, char>;

const int N = 5, IDMAX = 1e7, INF = 0x3f3f3f3f;

int n, m;
vector<vector<PII>> mutex = vector<vector<PII>>(N);
PIC info[IDMAX]; // first:等级 second:科目序号
char mapping[4] = {'A', 'C', 'M', 'E'};

void debug() {
    for (auto i : mutex) {
        for (auto j : i) 
        cout << j.first << ' ' << j.second << ' ';
        cout << endl;
    }
}
// 如果A中两个人的成绩相等，要怎么排序，这可能会影响这两个人最后的排名，排名应当并列，假设前两个人成绩相同，则最终排名为 1 1 3 4 5，而非1 2 3 4 5
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int id, c, m, e;
        cin >> id >> c >> m >> e;
        int a = round((c + m + e) / 3);

        info[id].first = INF;
        mutex[0].push_back({a, id}); // A
        mutex[1].push_back({c, id}); // C
        mutex[2].push_back({m, id}); // M
        mutex[3].push_back({e, id}); // E
    }

    for (int i = 0; i < 4; ++i) 
        sort(mutex[i].begin(), mutex[i].end(), [](PII a, PII b) -> bool {return a.first > b.first;});

    for (int i = 0; i < 4; ++i) {
        int inx = 1;
        for (int j = 1; j <= mutex[i].size(); ++j) {
            int id = mutex[i][j - 1].second;
            if (!(j == 1 || mutex[i][j - 2].first == mutex[i][j - 1].first)) inx = j; // 第1位或和前面的成绩相等时，inx不需要改变，否则inx应当为次序计数器j的值
            if (inx < info[id].first) {
                info[id].first = inx;
                info[id].second = mapping[i];
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int id;
        cin >> id;
        if (!info[id].first) cout << "N/A" << endl;
        else cout << info[id].first << ' ' << info[id].second << endl;
    }
}
int main() {
    solve();
    return 0;
}