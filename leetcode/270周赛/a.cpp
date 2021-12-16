#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<bool> st;
    unordered_set<string> numset;

    void dfs(vector<int>& d, int u, string num) {
        if (num.size() && num[0] == '0') return;
        if (u == 3) {
            numset.insert(num);
            return;
        }
        bool pre[15] = {0};
        for (int i = 0; i < (int)d.size(); ++i) {
            if (num == "" && !d[i]) continue;
            if (pre[d[i]]) continue;
            if (!st[i]) {
                st[i] = true;
                pre[d[i]] = true;
                dfs(d, u + 1, num + to_string(d[i]));
                st[i] = false;
            }
        }

    }
    vector<int> findEvenNumbers(vector<int>& d) {
        int n = d.size();
        st = vector<bool>(n + 10, false);

        dfs(d, 0, "");

        vector<int> res;
        for (string num : numset) {
            int k = stoi(num);
            if (!(k & 1)) res.push_back(k);
        }

        sort(res.begin(), res.end());

        return res;
    }
};