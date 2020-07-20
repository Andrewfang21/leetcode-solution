class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int A[n + 5];
        A[0] = 1, A[n + 1] = 1;
        
        for (int i = 1; i <= n; i ++)
            A[i] = nums[i - 1];
    
        int dp[n + 5][n + 5];
        memset(dp, 0, sizeof(dp));
        
        for (int len = 1; len < n + 1; len ++) {
            for (int i = 1; i < n - len + 2; i ++) {
                int j = i + len - 1;
                for (int k = i; k < j + 1; k ++) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + A[i - 1] * A[k] * A[j + 1] + dp[k + 1][j]);
                }
            }
        }
        return dp[1][n];
    }
};