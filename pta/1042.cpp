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

constexpr int N = 60;
constexpr int INF = 0x3f3f3f3f;

string a[N], b[N], c[N];
int seq[N];

inline void init() {
    string c[] = {"S", "H", "C", "D"};
    int size = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 1; j <= 13; ++j)
            a[++size] = c[i] + to_string(j); 

    a[++size] = "J1";
    a[++size] = "J2";       
}
void solve() {
    init();

    int round;
    cin >> round;
    for (int i = 1; i <= 54; ++i) cin >> seq[i];

    for (int i = 0; i < round; ++i) {
        for (int j = 1; j <= 54; ++j) b[seq[j]] = a[j];
        // memcpy(a, b, sizeof b);
        for (int i = 1; i <= 54; ++i) a[i] = b[i];
    }

    for (int i = 1; i <= 54; ++i)
        if (i == 1) cout << b[i];
        else cout << ' ' << b[i];
    cout << endl;
}
inline void output(string a[], string b[]) {
    cout << "a: " << a[0] << ' ' << a[1] << endl;
    cout << "b: " << b[0] << ' ' << b[1] << endl;
}
void solve2() {
    string a[1] = {"a"};
    string b[1] = {"b"};
    memcpy(a, b, sizeof b);
    a[0] = "c";
    cout << a[0] << ' ' << b[0] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve2();
    return 0;
}
// https://blog.csdn.net/qq_40754866/article/details/105638895