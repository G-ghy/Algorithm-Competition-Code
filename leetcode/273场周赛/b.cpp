class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dire[30];

    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        dire['U' - 'A'] = 0;
        dire['R' - 'A'] = 1;
        dire['D' - 'A'] = 2;
        dire['L' - 'A'] = 3;

        vector<int> res;
        for (int i = 0; i < (int)s.size(); ++i) {
            int cnt = 0;
            int x = startPos[0], y = startPos[1];
            for (int j = i; j < (int)s.size(); ++j) {
                int direction = dire[s[j] - 'A'];
                x += dx[direction], y += dy[direction];
                if (x < 0 || x >= n || y < 0 || y >= n) break;
                ++cnt;
            }
            res.push_back(cnt);
        }

        return res;
    }
};