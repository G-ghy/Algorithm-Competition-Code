class Solution {
public:
    vector<int> pivotArray(vector<int>& ns, int p) {
        vector<int> small, mid, big;
        int n = ns.size();
        for (int i = 0; i < n; ++i)
            if (ns[i] < p) small.push_back(ns[i]);
            else if (ns[i] == p) mid.push_back(ns[i]);
            else big.push_back(ns[i]);
        
        vector<int> res;
        for (int num : small) res.push_back(num);
        for (int num : mid) res.push_back(num);
        for (int num : big) res.push_back(num);
        return res;
    }
};