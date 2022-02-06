class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& ns) {
        int n = ns.size();
        vector<int> pre(n + 10, 0);
        vector<int> ctn(n + 10, 0);

        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1];
            if (!ns[i - 1]) ++pre[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            ctn[i] = ctn[i + 1];
            if (ns[i] == 1) ++ctn[i];
        }

        int max = -1;
        vector<int> res;
        for (int i = 0; i <= n; ++i) {
            if (pre[i] + ctn[i] > max) {
                max = pre[i] + ctn[i];
                res.clear();
                res.push_back(i);
            } else if (pre[i] + ctn[i] == max) res.push_back(i);
        }

        return res;
    }
};