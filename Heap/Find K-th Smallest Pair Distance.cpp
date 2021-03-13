class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 1000000;
        
        int res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (k <= checkPairs(nums, m)) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        
        return res;
    }
    
    int checkPairs(vector<int> &nums, int k) {
        int res = 0;
        int l = 0, r = 1;
        while (r < nums.size()) {
            if (nums[r] - nums[l] <= k) {
                res += (r - l);
                r ++;
            } else l ++;
            
            if (l == r)     r ++;
        }
        return res;
    }
};