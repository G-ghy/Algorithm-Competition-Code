class Solution {
public:
    int preInx[100010], preCnt[100010];
    long long preV[100010];
    long long res[100010];

    vector<long long> getDistances(vector<int>& arrs) {
        int n = arrs.size();
        
        for (int i = 0; i < n; ++i) {
            int arr = arrs[i];
            long long t = (i - preInx[arr]) * preCnt[arr] + preV[arr];
            ++preCnt[arr];
            preInx[arr] = i;
            preV[arr] = t;
            res[i] += t;
        }
        
        memset(preCnt, 0, sizeof preCnt);
        memset(preInx, 0, sizeof preInx);
        memset(preV, 0, sizeof preV);
        for (int i = n - 1; ~i; --i) {
            int arr = arrs[i];
            long long t = (preInx[arr] - i) * preCnt[arr] + preV[arr];
            ++preCnt[arr];
            preInx[arr] = i;
            preV[arr] = t;
            res[i] += t;
        }

        vector<long long> intervals;
        for (int i = 0; i < n; ++i)
            intervals.push_back(res[i]);

        return intervals;
    }
};