#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
char str[2][30] = {
    "I hate that ", 
    "I love that "
};
void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        cout << str[i % 2];
    }
    if (n & 1) cout << "I hate it" << endl;
    else cout << "I love it" << endl;
}
int main() {
    solve();
    return 0;
}