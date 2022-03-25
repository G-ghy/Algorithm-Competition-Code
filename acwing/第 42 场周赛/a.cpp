#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 5010;

int n, m;
int a[N], b[N];

inline int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
inline int getLcm(int a, int b) {
    return a * b / gcd(a, b);
}
void solve() {
    int lcm = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        lcm = getLcm(lcm, b[i]);
    }

    int inx = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] * (lcm / b[i]) < a[inx]) inx = i;
    
    printf("%.6lf\n", 1.0 * m * (1.0 * a[inx] / b[inx]));
}
int main() {
    solve();
    return 0;
}