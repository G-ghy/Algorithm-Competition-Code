// constexpr int N = 1e5 + 10;
// int l[N], r[N]; // 维护高度的左右边界
// int in[N]; // 差分数组

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         memset(in, 0, sizeof in);
//         memset(l, -1, sizeof l);
//         memset(r, -1, sizeof r);

//         int maxH = 0;
//         for (int i = 0; i < n; ++i) {
//             maxH = max(maxH, height[i]);
//             ++in[1]; --in[height[i] + 1];
//             if (l[height[i]] == -1) l[height[i]] = r[height[i]] = i;
//             else r[height[i]] = i;
//         }

//         for (int i = 1; i <= n; ++i) in[i] += in[i - 1];

//         int res = 0;
//         for (int h = maxH; h; --h)
//             if (in[h] > 1) {
//                 for (int i = l[h]; i <= r[h]; ++i) {
//                     res += h - min(height[i], h);
//                     height[i] = h;
//                 }
//             }

//         return res;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};