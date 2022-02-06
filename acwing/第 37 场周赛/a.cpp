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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

void solve() {
    int a, b, x, y, n;
    cin >> n >> a >> b;

    bool flag = false;
    for (x = 0; x <= n / a; ++x) {
        y = (n - a * x) / b;
        if ((n - a * x) % b == 0) {
            flag = true;
            break;
        }
        if (flag) break;
    }

    if (flag) {
        cout << "YES\n";
        cout << x << ' ' << y << '\n';
    } else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// 扩展欧几里得
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

// constexpr int N = 
constexpr int INF = 0x3f3f3f3f;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b) {
        x = 1; y = 0;
        return a;
    }
    int gcd = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

void solve() {
    int a, b, x, y, n;
    cin >> n >> a >> b;
    
    int gcd = exgcd(a, b, x, y);
    
    int flag = true;
    if (n % gcd) flag = false;
    else {
        x *= n / gcd;
        y *= n / gcd;
        
        // 使两数成为非负数(从运行结果来看存在无法成为非负数的情况，eg：1 7 8，解得 7 -6，无法成为非负数，则无解)
        if (x < 0) {
            int cnt = 0;
            while (x < 0) {
                x += b / gcd;
                ++cnt;
            }
            y -= cnt * (a / gcd);
        } else if (y < 0) {
            int cnt = 0;
            while (y < 0) {
                y += a / gcd;
                ++cnt;
            }
            x -= cnt * (b / gcd);
        }
        
        // 保证x最小
        int cnt = 0;
        while (true) {
            if (x - b / gcd < 0 || y + (cnt + 1) * (a / gcd) < 0) break;
            x -= b / gcd;
            ++cnt;
        }
        y += cnt * a / gcd;
        
        if (x < 0 || y < 0) flag = false; // 分析中不容易考虑到的情况

    }
    
    if (flag) {
        cout << "YES\n";
        cout << x <<  ' ' << y << '\n';
    } else {
        cout << "NO\n";
    }
    
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}