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

constexpr int N = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;

struct Node {
    string address;
    char data;
    int next;
}node[N];

int p1, p2, n;
bool st[N];

void solve() {
    cin >> p1 >> p2 >> n;
    for (int i = 0; i < n; ++i) {
        string address;
        char data;
        int next;
        
        cin >> address >> data >> next;
        int inx = stoi(address);
        node[inx].address = address;
        node[inx].data = data;
        node[inx].next = next;
    }

    while (p1 != -1) {
        st[p1] = true;
        p1 = node[p1].next;
    }
    
    bool flag = false;
    while (p2 != -1) {
        if (st[p2]) {
            flag = true;
            break;
        }
        p2 = node[p2].next;
    }

    if (flag) cout << node[p2].address << endl;
    else cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}