class Solution {
public:
    int minimumCost(vector<int>& c) {
        int res = 0;
        sort(c.begin(), c.end());
        
        int cnt = 0;
        int i = (int)c.size() - 1;
        while (~i) {
            if (cnt == 2) {
                cnt = 0;
                --i;
                continue;
            }
            res += c[i];
            ++cnt;
            --i;
        }

        return res;
    }
};