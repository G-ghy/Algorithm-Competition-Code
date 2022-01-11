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

constexpr int N = 25;
constexpr int INF = 0x3f3f3f3f;

unordered_map<string, vector<string>> mav;
unordered_map<string, unordered_set<string>> mas;
unordered_map<string, vector<string>> res;

void solve() { 
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string name, tele;
        int k;

        cin >> name >> k;
        for (int j = 0; j < k; ++j) {
            cin >> tele;
            if (!mas[name].count(tele)) {
                mas[name].insert(tele);
                mav[name].emplace_back(tele);
            }
        }
    }
    
    // for (auto person : mav) {
    //     cout << person.first << endl;
    //     for (string tele : person.second) cout << tele << ' ';
    //     cout << endl;
    // }

    for (auto person : mav) {
        string name = person.first;
        auto teleVec = person.second;
        // 判断teleVec[i]是否为teleVec[j]的后缀
        for (int i = 0; i < (int)teleVec.size(); ++i) {
            bool flag = false;
            for (int j = 0; j < (int)teleVec.size(); ++j) {
                if (i == j) continue;
                if (teleVec[i].size() > teleVec[j].size()) continue;
                if (teleVec[j].substr((int)teleVec[j].size() - (int)teleVec[i].size()) == teleVec[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) res[name].emplace_back(teleVec[i]);
        }
    }

    // 输出答案
    cout << res.size() << '\n';
    for (auto person : res) {
        string name = person.first;
        auto teleVec = person.second;
        
        cout << name << ' ' << (int)teleVec.size() << ' ';
        for (string tele : teleVec) cout << tele << ' ';
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}