#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

constexpr int N = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;

// 把所有1放到一起，也就是要框定一个给定区间，把所有1都放进来
// 那需要的操作不就是框定区间中0的个数吗
// 这么浅显的道理说什么都没想出来，懵逼了
// 计算0的个数等价于计算1的个数
class Solution {
public:
    int pre1[N];
    int pre2[N];
    
    int minSwaps(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> vec(2 * n + 1, 0);

        for (int i = 0, j = 1; i < n; ++i, ++j) vec[j] = nums[i];
        for (int i = 0, j = n + 1; i < n; ++i, ++j) vec[j] = nums[i];
        
        // 计算前缀和
        for (int i = 1; i <= 2 * n; ++i) vec[i] += vec[i - 1];

        // 计算1个个数
        int len = 0;
        for (int i = 0; i < n; ++i) len += nums[i];

        int res = len + 1;s
        for (int i = 1; i <= 2 * n - len + 1; ++i) {
            int j = i + len - 1;
            res = min(res, len - (vec[j] - vec[i - 1]));
        }

        return res;
    }
};

void solve() {
    vector<int> nums = {0,1,1,1,0,0,1,1,0};
    Solution solution;
    cout << solution.minSwaps(nums) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}