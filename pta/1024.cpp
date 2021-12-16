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

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int times;
vector<int> A, B;

inline vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < (int)A.size() || i < (int)B.size(); ++i) {
        if (i < (int)A.size()) t += A[i];
        if (i < (int)B.size()) t += B[i];

        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    A = C;
    return C;
}
inline bool check(vector<int> &A) {
    B = A;
    reverse(B.begin(), B.end());
    vector<int> C = add(A, B);
    int n = C.size();
    for (int i = 0; i < n / 2; ++i)
        if (C[i] != C[n - i - 1]) return false;
    return true;
}
void solve() {
    string num;
    cin >> num >> times;

    for (int i = (int)num.size() - 1; ~i; --i) A.push_back(num[i] - '0');
    
    int flag = -1;
    int n = A.size();
    for (int i = 0; i < n / 2; ++i)
        if (A[i] != A[n - i - 1]) {
            flag = -2;
            break;
        }

    // 本身是回文：flag==-1，不是回文：flag==-2
    // 如果本身就是回文数，则不需要进行操作，没想到这一点
    if (flag == -2)
        for (int i = 1; i <= times; ++i)
            if (check(A)) {
                flag = i;
                break;
            }

    if (flag == -1) flag = 0;
    if (flag == -2) flag = times;
    for (int i = (int)A.size() - 1; ~i; --i) cout << A[i];
    cout << endl;
    cout << flag << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}


