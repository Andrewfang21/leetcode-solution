class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        
        int dp[105];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = dp[1] = nums[0];
        for (int i = 2; i < nums.size() - 1; i ++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        int first = dp[nums.size() - 2];
        
        dp[0] = 0, dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i ++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        int second = dp[nums.size() - 1];
        
        return max(first, second);
    }
};