class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> answer;
        for (int mask = 0; mask < (1 << len); mask ++) {
            vector<int> currSubset;
            for (int i = 0; i < len; i ++) {
                int bitIsOn = (mask & (1 << i));
                if (bitIsOn)    currSubset.push_back(nums[i]);
            }
            answer.push_back(currSubset);
        }
        
        return answer;
    }
};