#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

constexpr int N = 1e5 + 10;

char str[N];

void solve() {
    scanf("%s", str);

    int cnt = 0;
    for (int i = 0; i < strlen(str) - 1; ++i)
        if (str[i] == str[i + 1]) ++ cnt;

    printf("%d\n", strlen(str) + cnt);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}