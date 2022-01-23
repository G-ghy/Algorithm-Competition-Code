constexpr int mod = 1e9 + 7;

class Solution {
public:
    int numberOfWays(string c) {
        int n = c.size();
        
        // 这个特判在写代码之前是没有想到的，写完之后通过自己出数据才发现这个问题
        int cnt = 0;
        for (int i = 0; i < n; ++i) 
            if (c[i] == 'S') ++ cnt;
        if (cnt < 2 || cnt & 1) return 0;
        
        bool first = true;
        vector<int> num;
        int i = 0;
        while (i < n) {
            if (c[i] == 'P') {
                ++i;
                continue;
            }
            if (first) first = false;
            else {
                int pre = i;
                ++i;
                while (i < n && c[i] == 'P') ++i;
                if (c[i] == 'S') {
                    num.push_back(i - pre);
                }
            }
            ++i;
        }
        
        long long res = 1;
        for (int x : num) res = (res * x) % mod;

        return res;
    }
};