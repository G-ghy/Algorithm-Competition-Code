// 首先拿到这道题，首先想的是图论问题，想到添加虚拟源点；甚至看到0，1，2还想到了带权并查集
// 并查集要看的是两点之间的关系，我还尝试着将关系等价成吃与被吃的关系，相当于食物链，但是不符合，pass掉
// 图论如果要枚举，当找到一个坏人时，它连出去的边要变成两条0和1，而且还要动态加边(只有遍历到它发现是坏人了才会加边)，这没办法实现
// 然后观察数据范围发现n才15，也就是说暴力都是可以的
// 仅仅想到这里是不知道怎么暴力的，只有想到下面的东西才会暴力
// 坏人既可以说真话，也可以说假话，相当于万能牌，换句话说坏人说的都没用
// 所以只要好人说的没产生矛盾，就不会有矛盾
// 所以枚举好人，判断图中是不是产生矛盾，统计人数最大值

class Solution {
public:
    int maximumGood(vector<vector<int>>& s) {
        int n = s.size(), m = s[0].size();

        int res = 0;
        for (int si = (1 << n) - 1; ~si; --si) {
            int a[16];
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = (si >> i) & 1;
                cnt += a[i];
            }
            
            bool flag = true;
            for (int i = 0; i < n; ++i)
                if (a[i]) {
                    for (int j = 0; j < m; ++j)
                        if (j != i && s[i][j] != 2 && a[j] != s[i][j]) {
                            flag = false;
                            break;
                        }
                    if (!flag) false;
                }
            if (flag) res = max(res, cnt);
        }

        return res;
    }
};