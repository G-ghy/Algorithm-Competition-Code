constexpr int INF = 0x3f3f3f3f;

// 两次错误尝试
// 1. 忽略了x本身的范围
// 2. 爆int了
class Solution {
public:
    int numberOfArrays(vector<int>& d, int l, int r) {
        int n = d.size();
        
        long long minn = l, maxx = r, offset = 0;
        for (int i = 0; i < n; ++i) {
            offset += d[i];
            minn = max(minn, l - offset);
            maxx = min(maxx, r - offset);
        }

        return max(0ll, (maxx - minn + 1));
    }
};