// bfs-方式1
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

bool st[N];

void solve() {
    int n, m;
    cin >> n >> m;

    int res = 0x3f3f3f3f;
    if (n >= m) res =n - m;
    else { // n < m;
        queue<int> q;
        int step = 1;
        q.push(n * 2);
        st[n * 2] = true;
        if (n - 1 > 0) {
            q.push(n - 1);
            st[n - 1] = true;
        }
        
        
        
        bool flag = false;
        while (q.size()) {
            int time = q.size();
            while (time--) {
                int t = q.front(); q.pop();
                if (t == m) {
                    flag = true;
                    break;
                }
                else if (t > m) res = min(res, step + t - m);
                else {
                    if (!st[t * 2]) {
                        q.push(t * 2);
                        st[t * 2] = true;
                    }
                    
                    if (t - 1 > 0 && !st[t - 1]) {
                        q.push(t - 1);
                        st[t - 1] = true;
                    }
                }
            }
            if (flag) break;
            ++step;
            if (step > res) break;
        }

        res = min(step, res);
    } 

    cout << res << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// bfs-方式2
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

constexpr int N = 20010;
constexpr int INF = 0x3f3f3f3f;

int d[N];

void solve() {
    memset(d, 0x3f, sizeof d);
    int n, m;
    cin >> n >> m;

    queue<int> q;
    q.push(n);
    d[n] = 0;

    while (q.size()) {
        int t = q.front(); q.pop();

        int items[] = {t - 1, t * 2};
        for (int x : items)
            if (x > 0 && x <= N && d[x] > d[t] + 1) {
                d[x] = d[t] + 1;
                q.push(x);
            }
    }

    cout << d[m] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

// 贪心
// 当时有考虑到贪心，但是不知道怎么贪
// 而且当时也想到了把运算逆转过来
// n到m，可以-1，也可以*2，则对应着m到n，可以+1，也可以/2
// /2要比*2更有限制性，因为只有偶数才可以除2
// 所以不是去看n到m，而是看m到n，对于解决问题可能更有利
// m与n的关系
// 1. m < n : 只能选择+1
// 2. m > n
//      a. m 是奇数 : 只能选择 + 1
//      b. m 是偶数 : 可以选择+1，也可以选择/2
// 唯一不确定的点就是m>n且m为偶数时，最终正确的贪心策略就是选择/2，但是在不证明的前提下，很难会直接这么想
// /2看似比+1可以更快得到结果，但总是会想到会不会有这么一种情况，先进行加法之后再/2会比直接/2更快得到结果
// 我在自己尝试证明时遇到的问题是：因为不知道具体的数值，所以操作次数是未知的
// 到底是+1还是/2只是一次操作，这次操作之后又该怎么处理？
// 问题是两种操作后结果不确定，没办法比较哪种方法的操作次数更少，
// 所以可以让这2种方案的结果变得相等，比较哪种方案的操作次数更少
// 在 m > n && m为偶数时
// 1. 选择+1操作，加上奇数不能/2，所以设+2k次，则变为m+2k，最后/2，结果为m/2+k，总共操作次数为2k+1
// 2. 选择/2操作，结果为m/2，之前所过，为了比较两种方案的次数，将m/2变为m/2+k需要k次，总共操作次数为k+1
// 所以首先/2再+1的操作次数要少于先+1再/2
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
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    while (m != n) {
        if (m < n) ++m;
        else if (m & 1) ++m;
        else m >>= 1;
        ++cnt;
    }

    cout << cnt << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
