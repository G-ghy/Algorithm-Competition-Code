#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include<string>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 前缀和预处理过程会超时，不太可行
// 最多查询1e5次，每次查询的复杂度应当控制在logn以下
// 从复杂度上来说，二分确实符合，但怎么会是二分呢？
// 问题抽象：无序数组中统计某一元素个数
// 确实没有想到预处理出出现的位置，
// 预处理每个元素出现的位置，存储其在原数组中的数组下标
// 二分当前容器下标，查找在>=left最小的原数组下标，其在当前容器中下标为i，<=right最大的原数组下标，其在当前容器中下标为j，
// j - i + 1即为答案
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> ma;
    
    // >= val的最小值
    int b_search_l(vector<int> &container, int val) {
        int l = 0, r = container.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (container[mid] >= val) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    // <= val的最大值
    int b_search_r(vector<int> &container, int val) {
        int l = 0, r = container.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (container[mid] <= val) l = mid;
            else r = mid - 1;
        }
        return l;
    }
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i)
            if (!ma.count(arr[i])) {
                vector<int> container;
                container.push_back(i);
                ma[arr[i]] = container;
            } else {
                vector<int> &container = ma[arr[i]];
                container.push_back(i);
            }
    }
    
    int query(int left, int right, int value) {
        int res = 0;
        if (!ma.count(value)) res = 0;
        else {
            int l = b_search_l(ma[value], left);
            int r = b_search_r(ma[value], right);
            // 这种二分写法最后一定会有结果但结果未必合法，需要进行判断，很容易忽略
            // 你应当想的是这里最后一定有值，但是这个值一定是答案吗
            if (ma[value][r] < left || ma[value][l] > right) res = 0;
            else res = r - l + 1;
        }
        return res;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */