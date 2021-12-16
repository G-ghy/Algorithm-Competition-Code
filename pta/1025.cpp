// 最终排名，原来处在第几组，在自己那组排第几
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

constexpr int N = 3e4 + 10;
constexpr int INF = 0x3f3f3f3f;

struct Person {
    string id;
    int score;
    int location_number; // 组别
    int final_rank; // 最终等级
    int local_rank; //  组内等级

    bool operator< (const Person &p) const {
        if (score != p.score) return score > p.score;
        return id < p.id; // 注意题目里有提到这一点，当成绩相同时必须有相同的final_rank同时按照id号递增的顺序输出
    }

    string to_string() {
        string info = "";
        info += "{";
        info += id;
        info += "," + std::to_string(score);
        info += "," + std::to_string(location_number);
        info += "," + std::to_string(final_rank);
        info += "," + std::to_string(local_rank);
        info += "}";
        return info;
    }
};

int n, k;
vector<vector<Person>> person;
vector<Person> tmp;

void getLocalRank(vector<Person> &p) {
    int n = p.size();
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        int inx = i - 1;
        if (!inx || p[inx].score == p[inx - 1].score) p[inx].local_rank = cnt;
        else {
            cnt = i;
            p[inx].local_rank = cnt;
        }
    }
}
void getFinalRank(vector<Person> &p) {
    int n = p.size();
    int cnt = 1;
    for (int i = 1; i <= n; ++i) {
        int inx = i - 1;
        if (!inx || p[inx].score == p[inx - 1].score) p[inx].final_rank = cnt;
        else {
            cnt = i;
            p[inx].final_rank = cnt;
        }
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        vector<Person> group = vector<Person>(k);
        person.push_back(group);
        for (int j = 0; j < k; ++j) {
            string id;
            int score;
            cin >> id >> score;
            person[i - 1][j].id = id;
            person[i - 1][j].score = score;
            person[i - 1][j].location_number = i;
        }
        sort(person[i - 1].begin(), person[i - 1].end());
        getLocalRank(person[i - 1]);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < (int)person[i].size(); ++j)
            tmp.push_back(person[i][j]);

    sort(tmp.begin(), tmp.end());
    getFinalRank(tmp);

    cout << (int)tmp.size() << endl;
    for (int i = 0; i < (int)tmp.size(); ++i)
        cout << tmp[i].id << ' ' << tmp[i].final_rank << ' ' << tmp[i].location_number << ' ' << tmp[i].local_rank << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}