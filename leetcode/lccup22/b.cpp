using PII = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr int N = 110;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class Solution {
public:
    int dis[N][N];
    bool st[N][N];
    queue<PII> q;

    bool get_dis(vector<string>& ma, int sx, int sy, int ex, int ey) {
        char op = ma[sx][sy];
        int x, y;
        int inx;

        if (op == '^') {
            inx = 0;
        } else if (op == 'v') {
            inx = 2; 
        } else if (op == '<') {
            inx = 3;
        } else if (op == '>') {
            inx = 1;
        }

        x = sx + dx[inx];
        y = sy + dy[inx];

        return !(x == ex && y == ey);
    }
    int conveyorBelt(vector<string>& ma, vector<int>& s, vector<int>& e) {
        memset(dis, 0x3f, sizeof dis);
        memset(st, 0, sizeof st);

        int n = ma.size(), m = ma[0].size();
        int sx = s[0], sy = s[1];
        int ex = e[0], ey = e[1];
        
        dis[sx][sy] = 0;
        st[sx][sy] = true;
        q.emplace(sx, sy);

        while (q.size()) {
            auto t = q.front(); q.pop();
            int x = t.first, y = t.second;
            
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                
                int distance = get_dis(ma, x, y, a, b);
                if (distance + dis[x][y] < dis[a][b]) {
                    dis[a][b] = distance + dis[x][y];
                    st[a][b] = true;
                    q.emplace(a, b);
                }
            }
        }

        return dis[ex][ey];
    }
};