class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l, r;
        int first = nums[0], end = nums[n - 1];

        for (l = 0; l < n; ++l)
            if (nums[l] != first) break;
        for (r = n - 1; ~r; --r)
            if (nums[r] != end) break;
        
        return max(0, r - l + 1);
    }
};