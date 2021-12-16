#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

constexpr int N = 5;

double a[N][N];
char odd[3] = {'W', 'T', 'L'};


void solve() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
    
    double res = 1;
    for (int i = 0; i < 3; ++i) {
        int pos = 0;
        for (int j = 0; j < 3; ++j)
            if (a[i][j] > a[i][pos]) pos = j;
        res *= a[i][pos];
        cout << odd[pos] << ' ';
    }

    printf("%.2lf\n", (res * 0.65 - 1) * 2);
}
int main() {
    solve();
    return 0;
}