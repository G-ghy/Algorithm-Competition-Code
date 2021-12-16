#include <iostream>
#include <cstring>

using namespace std;

constexpr int N = 1010, M = 2 * N;

int ka, kb;
double a[N], b[N], c[M];

void input(int &k, double a[]) {
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        cin >> a[x];
    }
}
void solve() {
    memset(a, 0, sizeof a); memset(b, 0, sizeof b); memset(c, 0, sizeof c);
    input(ka, a); input(kb, b);

    for (int i = 0; i < N; ++i)
        if (a[i]) {
            for (int j = 0; j < N; ++j)
                if (b[j]) c[i + j] += a[i] * b[j];
        }
    
    // 最终结果的指数最大为2000
    int cnt = 0;
    for (int i = 0; i < M; ++i)
        if (c[i]) ++cnt;
    cout << cnt;
    
    for (int i = M - 1; ~i; --i)
        if (c[i]) printf(" %d %.1lf", i, c[i]);
    cout << endl;
}
int main() {
    solve();
    return 0;
}