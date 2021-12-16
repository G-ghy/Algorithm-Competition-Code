#include <iostream>

using namespace std;

constexpr int N = 90;

int n, m;
int a[N][N];

/**
 * 1e8的数据量，线性扫描显然不可行
 * O(1)一般只会出现在数学找规律那种题目中
 * 因此初步推断复杂度应当为O(logn)
 * 寻找值，想到二分是具有合理性的
 * 可搜索空间1~m*n
 * 能否将区间划分为两个部分，使得每个部分具有一种性质
 * 对于序列中的某数x，如果x具有成为序列中的第k小的值的条件，即比x小的数据个数>=k个，那么x右侧的值一定具有满足成为第k小的值的条件；而x左侧的数据不一定具有该性质
 * 所以问题的核心在于如何快速计算出序列中比x小的值的数据个数
 * 查看每行中比x小的数据个数即可，按行枚举居然没想到，在x/i和n之间选个min就行了
 * 
 * 我总是去按照二维的空间去想，
 */
class Solution {
public:
    bool check(int x, int m, int n, int k) {
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
            cnt += min(x / i, n);
        return cnt >= k;
    }
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, m, n, k)) r = mid;
            else l = mid + 1;
        }
    }
};

int main() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j)
            cout << i * j << ' ';
        cout << endl;
    }

    return 0;
}