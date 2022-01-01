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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

void solve() {
    int vote;

    int num1 = 0, num0 = 0;
    while (cin >> vote, vote != -1) {
        if (vote == 1) ++num1;
        else ++num0;
    }    

    if (num1 == num0) cout << "Tie\n";
    else if (num1 > num0) cout << "Yes\n";
    else cout << "No\n";
    cout << to_string(num1) + ":" + to_string(num0) + "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}