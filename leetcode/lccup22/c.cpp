// class Solution {
// public:
//     int getMaximumNumber(vector<vector<int>>& m) {
//         sort(m.begin(), m.end(), [](vector<int> &a, vector<int> &b) -> bool {
//             return a[0] < b[0];
//         });

//         int nt = 0;
//         int x = 0, y = 0;
//         int cnt = 0;

//         for (int i = 0; i < (int)m.size(); ++i) {
//             int time = m[i][0];
//             int a = m[i][1], b = m[i][2];
            
//             int dis = abs(a - x) + abs(b - y);
//             if (dis <= time - nt) {
//                 nt = time;
//                 x = a;
//                 y = b;
//                 ++cnt;
//             }
//         }

//         return cnt;
//     }
// };

// using PII = pair<int, int>;
// using LL = long long;

// constexpr int N = 1e5 + 10;

// class Solution {
// public:
//     // 前一个击打了，这次击打/不击打
//     unordered_map<LL, pair<int, pair<int, int>>> prestrike;
//     unordered_map<LL, pair<int, pair<int, int>>> prenoStrike;
//     unordered_map<LL, int> prestrikeCnt;
//     unordered_map<LL, int> prenoStrikeCnt;
//     // 前一个未击打，这次击打/不击打
//     unordered_map<LL, pair<int, pair<int, int>>> strike;
//     unordered_map<LL, pair<int, pair<int, int>>> noStrike;
//     unordered_map<LL, int> strikeCnt;
//     unordered_map<LL, int> noStrikeCnt;

//     int getMaximumNumber(vector<vector<int>>& m) {
//         sort(m.begin(), m.end(), [](vector<int> &a, vector<int> &b) -> bool {
//             return a[0] < b[0];
//         });
        
//         for (int i = 0; i < (int)m.size(); ++i) {
//             int t = m[i][0];
//             int a = m[i][1], b = m[i][2];
            
//             if (!i) {
//                 int dis = abs(a - 1) + abs(b - 1);
//                 if (dis <= t) { // 可以击打第1个
//                     strike[t] = {t, {a, b}};
//                     strikeCnt[t] = 1;
//                     noStrike[t] = {0, {1, 1}};
//                     noStrikeCnt[t] = 0;

//                     prestrike[t] = {t, {a, b}};
//                     prestrikeCnt[t] = 1;
//                     prenoStrike[t] = {0, {1, 1}};
//                     prenoStrikeCnt[t] = 0;
//                 } else {        // 不可以击打第1个
//                     strike[t] = {0, {0, 0}};
//                     strikeCnt[t] = 0;
//                     noStrike[t] = {0, {0, 0}};
//                     noStrikeCnt[t] = 0;

//                     prestrike[t] = {0, {0, 0}};
//                     prestrikeCnt[t] = 0;
//                     prenoStrike[t] = {0, {0, 0}};
//                     prenoStrikeCnt[t] = 0;
//                 }
//             } else {
//                 int preCnt, pret, prex, prey, dis;
//                 // 前一个击打了
//                 preCnt = prestrikeCnt[m[i - 1][0]];
//                 pret = prestrike[m[i - 1][0]].first;
//                 prex = prestrike[m[i - 1][0]].second.first;
//                 prey = prestrike[m[i - 1][0]].second.first;
//                 dis = abs(a - prex) + abs(b - prey);

//                 if (dis <= t - pret) {
//                     // 击打
//                     prestrike[t] = {t, {a, b}};
//                     prestrikeCnt[t] = preCnt + 1;
//                     // 不击打
//                     prenoStrike[t] = {pret, {prex, prey}};
//                     prenoStrikeCnt[t] = preCnt;
//                 } else {
//                     // 击打
//                     prestrike[t] = {pret, {prex, prey}};
//                     prestrikeCnt[t] = preCnt;
//                     // 不击打
//                     prenoStrike[t] = {pret, {prex, prey}};
//                     prenoStrikeCnt[t] = preCnt;
//                 }

//                 // 前一个没有击打
//                 preCnt = noStrikeCnt[m[i - 1][0]];
//                 pret = noStrike[m[i - 1][0]].first;
//                 prex = noStrike[m[i - 1][0]].second.first;
//                 prey = noStrike[m[i - 1][0]].second.first;
//                 dis = abs(a - prex) + abs(b - prey);

//                 if (dis <= t - pret) { // 这个可以击打
//                     // 击打
//                     strike[t] = {t, {a, b}};
//                     strikeCnt[t] = preCnt + 1;
//                     // 不击打
//                     noStrike[t] = {pret, {prex, prey}};
//                     noStrikeCnt[t] = preCnt;
//                 } else { // 这个不可以击打
//                     // 击打
//                     strike[t] = {pret, {prex, prey}};
//                     strikeCnt[t] = preCnt;
//                     // 不击打
//                     noStrike[t] = {pret, {prex, prey}};
//                     noStrikeCnt[t] = preCnt;
//                 }
//             }
//         }

//         LL lasttime = m[(int)m.size() - 1][0];
//         return max(max(prestrikeCnt[lasttime], prenoStrikeCnt[lasttime]), max(strikeCnt[lasttime], noStrikeCnt[lasttime]));
//     }
// };

// using PII = pair<int, int>;
// using LL = long long;

// constexpr int N = 5;

// int dx[] = {-1, 0, 1, 0};
// int dy[] = {0, 1, 0, -1};

// queue<pair<pair<int, int>, pair<int, pair<int, int>>>> q;
// int cnt[N][N];
// LL g[N][N];

// class Solution {
// public:

//     int getMaximumNumber(vector<vector<int>>& mo) {
//         memset(g, 0, sizeof g);
//         for (int i = 0; i < (int)mo.size(); ++i) {
//             int v = mo[i][0], x = mo[i][1], y = mo[i][2];
//             g[x][y] = v;
//         }

//         int n = 3, m = 3;
//         memset(cnt, 0, sizeof cnt);
        
//         q.push({{-1, -1}, {0, {1, 1}}});
//         cnt[1][1] = 0;

//         while (q.size()) {
//             auto t = q.front(); q.pop();
//             int px = t.first.first, py = t.first.second;
//             int x = t.second.second.first, y = t.second.second.second;
//             int step = t.second.first;

//             for (int i = 0; i < 4; ++i) {
//                 int a = x + dx[i], b = y + dy[i];
//                 if (a < 0 || a >= n || b < 0 || b >= m || (a == px && b == py)) continue;

//                 if (step + 1 <= g[a][b]) {
//                     cnt[a][b] = max(cnt[a][b], cnt[x][y] + 1);
//                 } else {
//                     cnt[a][b] = cnt[x][y];
//                 }
//                 q.push({{x, y}, {cnt[a][b], {a, b}}});
//             }
//         }

//         int res = -0x3f3f3f3f;
//         for (int i = 0; i < 3; ++i)
//             for (int j = 0; j < 3; ++j)
//                 res = max(res, cnt[i][j]);

//         return res;
//     }
// };

using PII = pair<int, int>;
using LL = long long;

constexpr int N = 5;
constexpr int INF = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

LL g[N][N];
bool st[N][N];
int res = 0;
int n = 3, m = 3;

class Solution {
public:
    void dfs(int x, int y, int t, int cnt) {
        bool flag = false;

        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) continue;

            flag = true;
            st[a][b] = true;
            if (t + 1 <= g[a][b]) {
                cout << a << ' ' << b << ' ' << g[a][b] << endl;
                dfs(a, b, g[a][b] + 1, cnt + 1);
            } else {
                dfs(a, b, t + 1, cnt);
            }
            st[a][b] = false;
        }

        if (!flag) res = max(res, cnt);
    }
    int getMaximumNumber(vector<vector<int>>& mo) {
        memset(g, 0, sizeof g);
        for (int i = 0; i < (int)mo.size(); ++i) {
            int v = mo[i][0], x = mo[i][1], y = mo[i][2];
            g[x][y] = v;
        }
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) cout << g[i][j] << ' ';
            cout << endl;
        }

        res = 0;
        st[1][1] = true;
        dfs(1, 1, 0, 0);

        return res;
    }
};