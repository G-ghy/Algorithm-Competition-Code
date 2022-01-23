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

constexpr int N = 50010;
constexpr int INF = 0x3f3f3f3f;

struct Seq{
    string name;
    int idx, group;
}allName[2 * N];

int n;
string names[N];
bool best[N], worst[N];
int bres[N], wres[N];

// 给定若干字符串，规定排列顺序为字典树
// 规定字符串的最好排列为字典序最小的排列，最坏排列为字典序最大的排列
// 询问每一个字符串在最好情况下处在所有字符串中排列的第几位，最坏情况下排列在第几位
// 问题可以抽象为询问一个字符串处在最好情况下，其他字符串都处在最坏情况下，它处在排列中的第几位
// 暴力想法就是把每一个字符串修改为最好情况(最坏情况)，将其他字符串修改为最坏情况(最好情况)，放在一起排个序
// 每个字符串自身的排序是nlogn，每次确定在序列中的位置还需要一次排序也是nlog，显然会超时
// 但是可以预处理出每一个字符串的最好排列和最坏排列，因此想到了所有这些排列放在一起排列，遍历的同时维护最好排列和最坏排列的数量，即可计算得出一个字符串处在哪个位置
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> names[i];

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string t = names[i];
        sort(t.begin(), t.end());
        allName[cnt++] = {t, i, 0}; // best
        sort(t.begin(), t.end(), [](char a, char b) -> bool {return a > b;});
        allName[cnt++] = {t, i, 1}; // worst
    }

    sort(allName, allName + cnt, [](Seq &a, Seq &b) -> bool {
        return a.name < b.name;
    });

    int cntBest = 0, cntWorst = 0;
    for (int i = 0; i < cnt; ++i) {
        string name = allName[i].name;
        int idx = allName[i].idx, group = allName[i].group;

        if (!group) { // best
            ++cntBest;
            best[idx] = true;
            bres[idx] = cntWorst - worst[idx];
        } else { // worst
            ++cntWorst;
            worst[idx] = true;
            wres[idx] = cntBest - best[idx];
        }
    }

    for (int i = 0; i < n; ++i) cout << bres[i] + 1 << ' ' << wres[i] + 1 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}