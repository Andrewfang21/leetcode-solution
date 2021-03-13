class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        
        int l = 0, r = 0;
        
        vector<string> ranges;
        while (r < nums.size() - 1) {
            while (r < nums.size() - 1 && nums[r] == nums[r + 1] - 1)
                r ++;
            if (r < nums.size() - 1 && nums[r] != nums[r + 1] - 1) {
                if (l != r)
                    ranges.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
                else
                    ranges.push_back(to_string(nums[l]));
                
                l = r + 1;
                r ++;
            }
        }
        
        if (r < nums.size()) {
            if (l != r)
                ranges.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            else
                ranges.push_back(to_string(nums[l]));
        }
        
        return ranges;
    }
};