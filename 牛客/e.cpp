#include <iostream>
#include <algorithm>
#include <cstring>
#include <windows.h>

using namespace std;

constexpr int N = 1e5 + 10;

int n, m;
int a[N];

bool check(int mid) {
    int cnt = 0;
    for (int i = 1; i < N; ++i) {
        cnt += a[i] / mid;
        if (a[i] % mid) ++cnt;
    }
    
    return cnt <= m;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }
    
    int l = 1, r = 100000;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    int cnt = 0;
    for (int i = 1; i < N; ++i) {
        cnt += a[i] / l;
        if (a[i] % l) ++cnt;
    }
    /**
     * 能够判断以下代码正确性的一组数据
     * 5 4
     * 1 1 1 1 2
     * 
     * 分法：1&1 1 1 2
     * 人数最多的组是2个人
     * 
     * 错误原因在于对有解的判定条件分析错误
     * 题目中说的是需要恰好分为m组
     * 因此我的判定条件就是按照每组l个人来分，必须恰好分成m组才为合法解
     * 但是有解的条件实际应当为<=m，小于m意味着我们确定的每组人数较多，因此分成的组数也就少了，
     * 但是完全可以从分好的组中拿出来单独成为一个人，或者几个人从而凑够m组，因此如果分成的组数<m，是可以凑成m组的
     * 
     * 这道题目从二分那就已经分析错了，但是并没有意识到
     * 因为在左区间移动时，相当于认定了答案在左区间，即分成的组数<=m那一边，但是当时我认为的只有相等那一个点才算是答案
     */
    // 错误的
    // if (cnt == m) cout << l << endl;
    // else cout << -1 << endl;
    // 正确的
    if (cnt <= m) cout << l << endl;
    else cout << -1 << endl;
}
class T {
    public:
    int val;
    T() {
        val = 5;
    }
};
class Solution {
public:
    void dfs(int x, vector<int> &fullarr, vector<int> &st, vector<vector<int>> &res, vector<vector<int>> &nums) {
        int n = nums.size();
        if (x == n) {
            res.push_back(fullarr);
            return;
        }
        for (int i = 0; i < n; ++i)
            if (!st[i]) {
                st[i] = true;
                fullarr.push_back(nums[i]);
                dfs(x + 1);
                st[i] = false;
                fullarr.pop_back();
            }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> fullarr;
        vector<int> st = vector<int>(nums.size(), false);
        vector<vector<int>> res;

        dfs(0, fullary, st, res, nums);

        return res;
    }
    do {

    } while (next_permutation())
};
int main() {
    // memset(a, 0, sizeof a);
    // solve();
    return 0;
}