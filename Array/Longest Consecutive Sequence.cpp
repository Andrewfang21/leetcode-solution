class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        sort(nums.begin(), nums.end());
        int res = 1;
        
        nums.resize(distance(nums.begin(), unique(nums.begin(), nums.end())));
        
        int pos = 1;
        while (pos < nums.size()) {
            int currLen = 1;
            while (pos < nums.size() && nums[pos] == nums[pos - 1] + 1) {
                pos ++;
                currLen ++;
            }
            
            res = max(res, currLen);
            pos ++;
        }
        
        return res;
    }
};