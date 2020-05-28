class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;
        if (nums.size() == 2) {
            if (nums[0] == nums[1])
                return true;
            return false;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size() - 1; i ++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i + 1])
                return true;
        }
        
        return false;
    }
};