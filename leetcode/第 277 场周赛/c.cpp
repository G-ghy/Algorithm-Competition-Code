constexpr int N = 1e6 + 10;

class Solution {
public:
    vector<int> findLonely(vector<int>& ns) {
        unordered_map<int, int> cnt;
        int n = ns.size();

        for (int i = 0; i < n; ++i) {
            if (!cnt.count(ns[i])) {
                cnt[ns[i]] = 1;
            } else {
                ++cnt[ns[i]];
            }
        }
            

        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (cnt[ns[i]] == 1 && !cnt.count(ns[i] - 1) && !cnt.count(ns[i] + 1))
                res.push_back(ns[i]);

        return res;
    }
};