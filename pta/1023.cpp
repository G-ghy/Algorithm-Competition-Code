#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

constexpr int INF = 0x3f3f3f3f;

vector<int> mul(vector<int> &A, int b) {
    vector<int> C;

    int t = 0;
    for (int i = 0; i < (int)A.size() || t; ++i) {
        if (i < (int)A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && !C.back()) C.pop_back();
    return C;
}
void solve() {
    string num;
    cin >> num;
    vector<int> A, C, T;
    for (int i = (int)num.size() - 1; ~i; --i) 
        A.push_back(num[i] - '0');
    C = mul(A, 2);
    T = C;
    
    bool flag = (A.size() == C.size());
    if (flag) {
        sort(A.begin(), A.end());
        sort(T.begin(), T.end());
        for (int i = 0; i < (int)A.size(); ++i)
            if (A[i] != T[i]) {
                flag = false;
                break;
            }
    }
    
    cout << ((flag) ? "Yes" : "No") << endl;
    for (int i = (int)C.size() - 1; ~i; --i) cout << C[i];
    cout << endl; 

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}