struct Point {
    int dis;
    int price;
    int r;
    int c;
};

// 错了2次
// 第一次是由于使用全局变量导致的错误
// 第二次是自认为起点一定是1，没考虑到起点也可以是答案中的点
class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size(), m = grid[0].size();
        int low = pricing[0], high = pricing[1];
        int sx = start[0], sy = start[1];
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        vector<Point> ps;
        vector<vector<bool>> st;
        vector<vector<int>> dis;
        st = vector<vector<bool>> (n, vector<bool>(m, false));
        dis = vector<vector<int>> (n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        if (grid[sx][sy]) {
            q.emplace(sx, sy);
            st[sx][sy] = true;
            if (grid[sx][sy] >= low && grid[sx][sy] <= high) 
                ps.push_back({dis[sx][sy], grid[sx][sy], sx, sy});
        }
        
        while (q.size()) {
            auto t = q.front(); q.pop();
            int x = t.first, y = t.second;
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m || st[a][b] || !grid[a][b]) continue;
                dis[a][b] = dis[x][y] + 1;
                st[a][b] = true;
                q.emplace(a, b);
                if (grid[a][b] != 1 && grid[a][b] >= low && grid[a][b] <= high)
                    ps.push_back({dis[a][b], grid[a][b], a, b});
            }
        }

        sort(ps.begin(), ps.end(), [](Point &a, Point &b) -> bool {
            if (a.dis != b.dis) return a.dis < b.dis;
            if (a.price != b.price) return a.price < b.price;
            if (a.r != b.r) return a.r < b.r;
            return a.c < b.c;
        });

        int cnt = 0;
        vector<vector<int>> res;
        for (auto t : ps) {
            int x = t.r, y = t.c;
            vector<int> coordinate;
            coordinate.push_back(x);
            coordinate.push_back(y);
            res.push_back(coordinate);
            ++cnt;
            if (cnt >= k) break;
        }
        
        return res;
    }
};