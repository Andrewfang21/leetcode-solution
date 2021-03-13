class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i ++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    res.emplace_back(vector<int> {nums[i], nums[l], nums[r]});
                    l ++, r --;
                    while (nums[l] == nums[l - 1] && l < r)
                        l ++;
                } else if (nums[i] + nums[l] + nums[r] < 0)
                    l ++;
                else if (nums[i] + nums[l] + nums[r] > 0)
                    r --;
            }
        }
        
        return res;
    }
};