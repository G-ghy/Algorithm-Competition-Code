using LL = long long;

class Solution {
public:
    long long minimumDifference(vector<int>& ns) {
        int n = ns.size();
        vector<int> t(n + 10);
        for (int i = 1; i <= n; ++i) t[i] = ns[i - 1];

        // 预处理前面数据中最小的n个数的和
        priority_queue<int> bh; // 大顶堆
        vector<LL> pre(n + 10, 0);
        for (int i = 1; i <= 2 * (n / 3); ++i) {
            pre[i] = pre[i - 1];
            if (bh.size() < n / 3) {
                pre[i] += t[i];
                bh.push(t[i]);
            } else {
                int top = bh.top();
                if (t[i] < top) {
                    pre[i] -= top - t[i];
                    bh.pop();
                    bh.push(t[i]);
                }
            }
        }

        // 预处理后面前面数据中最大的n个数的和
        priority_queue<int, vector<int>, greater<int>> sh; // 小顶堆
        vector<LL> ctn(n + 10, 0);
        for (int i = n; i >= n / 3; --i) {
            ctn[i] = ctn[i + 1];
            if (sh.size() < n / 3) {
                ctn[i] += t[i];
                sh.push(t[i]);
            } else {
                int top = sh.top();
                if (t[i] > top) {
                    ctn[i] += t[i] - top;
                    sh.pop();
                    sh.push(t[i]);
                }
            }
        }

        LL res = 1e18;
        for (int i = n / 3; i <= 2 * (n / 3); ++i)
            if (pre[i] - ctn[i + 1] < res) res = pre[i] - ctn[i + 1];
        
        return res;
    }
};

// 主要的算法是使用堆动态求前n个数最小值和后n个数最大值
// 但是分析到使用这个算法之前还有一些分析过程是我没有想到的
// 首先这道题需要枚举1段和3段的分界点
// 为什么会这样想？
// 其实正常的思考流程一定不是直接想分界点，而是两段
// 题目明确提到最终的形态是2段，令前段减后段的结果尽可能小，则应当令前段尽可能小，后段尽可能大(按理说这种想法应当是有的，可惜我当时连这个都没有去想)
// 现在反思来看，做题过程中不应当过分拘泥于如何抽出这n个数据
// 既然考虑到两段了，而且期望前段的和尽可能小，后段和尽可能大
// 那么应当去想，如何可以求出前段和的最小值，后段和的最大值
// 想要求值，其实就必须把两端分开了，所以这才到的分界点
// 前段和后段抽出哪些数据并不重要，重要的是如何使得剩下的值和最小和最大
// 所以这就顺水推舟走到了最上面提到的算法上
// 总结来看，我之所以不会做，总是在想如何抽出这n个数据，抽出哪些数据，
// 最明显的该有的分段的思想都没有考虑到