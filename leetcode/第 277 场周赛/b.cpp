class Solution {
public:
    vector<int> rearrangeArray(vector<int>& ns) {
        int n = ns.size();

        vector<int> posi, neg;

        for (int n : ns)
            if (n > 0) posi.push_back(n);
            else neg.push_back(n);

        vector<int> res;
        bool isPosi = true;
        int l = 0, r = 0;
        while (l < n / 2 || r < n / 2) {
            if (isPosi) {
                isPosi = false;
                res.push_back(posi[l]);
                ++l;
            } else {
                isPosi = true;
                res.push_back(neg[r]);
                ++r;
            }
        }

        return res;
    }
};