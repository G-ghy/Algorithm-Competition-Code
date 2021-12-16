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

constexpr int N = 2020, M = N * N;
constexpr int INF = 0x3f3f3f3f;

struct ds {
    int peopleNum;
    int sumVal;
    string headName;
} ds[N];

int n, k;
int p[N];
int h[N], e[M], ne[M], w[M], idx;
int size; //连通块个数
int inx;
unordered_map<string, int> personInx; // 将姓名映射为序号,便于建图
unordered_map<int, string> personName; // 将序号映射为姓名，输出需要使用
int personVal[N]; // 每个人的权重
bool st[M];
vector<int> resInx;

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
inline void add(int a, int b, int c) {
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
inline void output() {
    for (int i = 0; i < inx; ++i) {
        cout << personName[i] << ": ";
        for (int j = h[i]; ~j; j = ne[j]) cout << personName[e[j]] << ' ';
        cout << endl;
    }
}
void solve() {
    memset(h, -1, sizeof h);
    for (int i = 0; i < N; ++i) p[i] = i; // 初始化并查集

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string a, b;
        int c;
        cin >> a >> b >> c;
        if (!personInx.count(a)) {
            personName[inx] = a;
            personInx[a] = inx++;
        }
        if (!personInx.count(b)) {
            personName[inx] = b;
            personInx[b] = inx++;
        }

        int ainx = personInx[a], binx = personInx[b];
        int painx = find(ainx), pbinx = find(binx);
        add(ainx, binx, c); add(binx, ainx, c);
        personVal[ainx] += c; personVal[binx] += c;
        if (painx != pbinx) p[painx] = pbinx;
    }

    for (int i = 0; i < inx; ++i) {
        int id = find(i);
        ++ds[id].peopleNum;
        for (int j = h[i]; ~j; j = ne[j]) {
            if (st[j]) continue;
            st[j] = st[j ^ 1] = true;
            ds[id].sumVal += w[j];
        }
        if (ds[id].headName == "" || personVal[personInx[ds[id].headName]] < personVal[i]) ds[id].headName = personName[i];
    }

    for (int i = 0; i < inx; ++i)
        if (ds[i].peopleNum > 2 && ds[i].sumVal > k) resInx.push_back(i);

    sort(resInx.begin(), resInx.end(), [](int i, int j) {
        return ds[i].headName < ds[j].headName;
    });

    cout << resInx.size() << endl;
    for (int i : resInx) cout << ds[i].headName << ' ' << ds[i].peopleNum << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}