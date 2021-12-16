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

constexpr int N = 2510;
constexpr int INF = 0x3f3f3f3f;

int n, k;
vector<string> c[N];
unordered_map<string, vector<int>> clist;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        int id, sn;
        cin >> id >> sn;
        for (int j = 0; j < sn; ++j) {
            string name;
            cin >> name;
            c[id].push_back(name);
        }
    }

    for (int i = 1; i <= k; ++i) {
        for (string name : c[i]) 
            clist[name].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        string name;
        cin >> name;
        
        cout << name << ' ' << clist[name].size();
        for (int id : clist[name]) cout << ' ' << id;
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}