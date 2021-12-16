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
    string name, sex, id;
    int grade;
    int mingrade = INF, maxgrade = -INF;
    string mname, mid;
    string fname, fid;

    cin >> n; 
    for (int i = 0; i < n; ++i) {
        cin >> name >> sex >> id >> grade;
        if (sex == "M" && grade < mingrade) {
            mingrade = grade;
            mname = name;
            mid = id;
        } else if (sex == "F" && grade > maxgrade) {
            maxgrade = grade;
            fname = name;
            fid = id;
        }
    }

    if (maxgrade == -INF) cout << "Absent" << endl;
    else cout << fname << ' ' << fid << endl;
    if (mingrade == INF) cout << "Absent" << endl;
    else cout << mname << ' ' << mid << endl;
    if (mingrade == INF || maxgrade == -INF) cout << "NA" << endl;
    else cout << maxgrade - mingrade << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}