#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

    // 在分析阶段，显然顺序对于问题的答案没有影响，但排序后看似具有了更好的性质，所以一定是选择先排个序
    // 但是在BF的3重循环中，排序并没有起到作用
    // 是在正解的分析中才会起到作用

    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> res;
        int n = a.size();

        sort(a.begin(), a.end());

        // 按照从小到大的顺序依次枚举
        // 满足a[i] <= a[j] <= a[k];
        for (int i = 0; i < n; ++i) {
            // 最小值>0，则和一定>0，不需往后继续枚举了
            if (a[i] > 0) break;
            // 例如 -1 0 1 和 -1 0 1，此前考虑过-1了，就不需要再从-1开始了
            while (i < n && i && a[i] == a[i - 1]) ++i;

            for (int j = i + 1; j < n; ++j) {
                    // 
                    for (int k = n - 1; k > j; --k) {
                        // k从大到小，如果a[i] + a[j] + a[k]可能的最大值都<0，则a[k]没必要再减小了
                        if (a[i] + a[j] + a[k] < 0) break;
                        if (a[i] + a[j] + a[k] == 0) {
                            vector<int> box = {a[i], a[j], a[k]};
                            res.push_back(box);
                        }
                    }
            }
        }

        return res;
    }
};
class Solution {
public:

    // 在分析阶段，显然顺序对于问题的答案没有影响，但排序后看似具有了更好的性质，所以一定是选择先排个序
    // 但是在BF的3重循环中，排序并没有起到作用
    // 是在正解的分析中才会起到作用

    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> res;
        int n = a.size();

        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) break;
            if (i && a[i] == a[i - 1]) continue;

            // 去重去的相同的答案，所以在答案出来之后去重
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = a[i] + a[l] + a[r];
                if (!sum) {
                    vector<int> box = {a[i], a[l], a[r]};
                    res.push_back(box);
                    while (l < r && a[l] == a[l + 1]) ++l;
                    while (l < r && a[r] == a[r - 1]) --r;
                } 
                else if (sum < 0) ++l;
                else if (sum > 0) --r;
            }
        }

        return res;
    }
};

int main() {
    Solution s = Solution();

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = s.threeSum(nums);
    for (auto vec : res) {
        for (int val : vec) cout << val << ' ';
        cout << endl;
    }
    return 0;
}