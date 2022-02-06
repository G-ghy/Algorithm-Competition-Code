class Solution {
public:
    unordered_set<int> st;
    int findFinalValue(vector<int>& ns, int original) {
        int n = ns.size();
        for (int i = 0; i < n; ++i) st.insert(ns[i]);
        while (true) {
            if (st.find(original) == -1) break;
            original *= 2;
        }
        return original;
    }
};