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

constexpr int N = 10;
constexpr int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    printf("AGC%03d\n", n >= 42 ? n + 1 : n);
}
int main() {
    solve();
    return 0;
}