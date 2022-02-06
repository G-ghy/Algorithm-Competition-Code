class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& ns) {
        int n = ns.size();
        vector<int> f, s;
        for (int i = 0; i < n; ++i)
            if (i & 1) f.push_back(ns[i]); // 奇数
            else s.push_back(ns[i]);

        sort(f.begin(), f.end(), [](int a, int b) -> bool {return a > b;});
        sort(s.begin(), s.end());
        
        vector<int> res;
        bool flag = true;
        int i = 0, j = 0;
        for (int k = 0; k < (int)f.size() + (int)s.size(); ++k) {
            if (flag) {
                res.push_back(s[j++]);
                flag = false;
            } else {
                res.push_back(f[i++]);
                flag = true;
            }
        }

        return res;
    }
};