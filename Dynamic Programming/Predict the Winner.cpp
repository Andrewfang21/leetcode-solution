class Solution {
public:
    int solve(int l, int r, int dp[25][25], vector<int> &nums) {
        if (l > r)  return 0;
        if (l == r)
            return dp[l][r] = nums[l];
        if (dp[l][r] != -1)
            return dp[l][r];
        
        int res = max(nums[l] - solve(l + 1, r, dp, nums), nums[r] - solve(l, r - 1, dp, nums));
        return dp[l][r] = res;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int dp[25][25];
        memset(dp, -1, sizeof(dp));
        
        int n = nums.size();
        solve(0, n - 1, dp, nums);
        return (dp[0][n - 1] >= 0);
    }
};