class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = -1, p = 1, n = nums.size(), res = 0;
        for (int r = 0; r < n; r ++) {
            p *= nums[r];
            while (l < r && p >= k)
                p /= nums[++ l];
            
            res += r - l;
        }
        return res;
    }
};