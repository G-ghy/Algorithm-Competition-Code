class Solution {
public:
    int getMinimumTime(vector<int>& t, vector<vector<int>>& f, int l) {
        long long sum = 0;
        for (int i = 0; i < (int)f.size(); ++i) {
            sum += t[f[i][0]] * ((f[i][1] + l - 1) / l);
        }
        return sum;
    }
};