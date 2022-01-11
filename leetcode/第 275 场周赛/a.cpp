class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_set<int> num;
        int n = matrix.size();

        bool flag = true;
        for (int i = 0; i < n; ++i) {
            num.clear();
            for (int j = 0; j < n; ++j) num.insert(matrix[i][j]);
            if ((int)num.size() != n) {
                flag = false;
                break;
            }
        }

        if (flag) {
            for (int i = 0; i < n; ++i) {
                num.clear();
                for (int j = 0; j < n; ++j) num.insert(matrix[j][i]);
                if ((int)num.size() != n) {
                    flag = false;
                    break;
                }
            }
        }

        return flag;
    }
};