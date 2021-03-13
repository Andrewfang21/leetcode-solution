class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(0, nums, res, subset);
        
        return res;
    }
    
    void dfs(int pos, vector<int>& nums, vector<vector<int>>& res, vector<int>& subset) {
        res.push_back(subset);
        for (int i = pos; i < nums.size(); i ++) {
            if (i != pos && nums[i] == nums[i - 1])
                continue;
            
            subset.push_back(nums[i]);
            dfs(i + 1, nums, res, subset);
            subset.pop_back();
        }
    }
};