// #include <cstring>
// #include <cstdio>
// #include <cmath>
// #include <iostream>
// #include<string>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <deque>
// #include <stack>
// #include <set>
// #include <map>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;

// constexpr int N = 1e5 + 10;
// constexpr int INF = 0x3f3f3f3f;

// int n, m;
// int a[N], b[N];
// int suma, sumb;
// int h[N], len;

// int find(int a[], int l, int r, int num) {
//     while (l < r) {
//         int mid = l + r >> 1;
//         if (a[mid] >= num) r = mid;
//         else l = mid + 1;
//     }
//     if (a[l] == num) return l;
//     return -1;
// }
// bool check(int a[], int n, int hn) {
//     int size = a[n] / hn;
//     int cnt = 0;
//     int i = 0;
//     while (i <= n) {
//         int next = find(a, i + 1, n, size + a[i - 1]);
//         if (next == -1) return false;
//         i = next + 1;
//     }
//     return true;
// }
// void solve() {
//     cin >> n >> m;   
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//         a[i] += a[i - 1];
//     }
//     for (int i = 1; i <= m; ++i) {
//         cin >> b[i];
//         b[i] += b[i - 1];
//     }
//     suma = a[n];
//     sumb = b[m];
    
//     int l = 1, r = min(n, m);
//     while (l < r) {
//         int mid = l + r + 1 >> 1;
//         if (check(a, n, mid)) cout << "ayes\n";
//         if (check(b, n, mid)) cout << "byes\n";
//         if (check(a, n, mid) && check(b, m, mid)) l = mid;
//         else r = mid - 1;
//     }

//     cout << l << '\n';
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     solve();
//     return 0;
// }


#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

int n, m;
int a[N], b[N];

int find(int b[], int l, int r, int num) {
    while (l < r) {
        int mid = l + r >> 1;
        if (b[mid] >= num) r = mid;
        else l = mid + 1;
    }
    if (b[l] == num) return l;
    else return 0;
}
void solve() {
    cin >> n >> m;   
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    int cnt = 0, bl = 1;
    for (int i = 1; i <= n; ++i) {
        int pos = find(b, bl, m, a[i]);
        if (b[pos] == a[i]) {
            bl = pos + 1;
            ++cnt;
        }
    }

    cout << cnt << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}