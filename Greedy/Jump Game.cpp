class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxSoFar = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (maxSoFar >= i) {
                maxSoFar = max(maxSoFar, i + nums[i]);
            }
        }
        
        return maxSoFar >= nums.size() - 1;
    }
};