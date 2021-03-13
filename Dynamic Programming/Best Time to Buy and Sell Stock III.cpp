class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(3));
        for (int j = 1; j <= 2; j ++) {
            int maxDiff = INT_MIN;
            for (int i = 1; i < prices.size(); i ++) {
                maxDiff = max(maxDiff, dp[i - 1][j - 1] - prices[i - 1]);
                dp[i][j] = max(dp[i - 1][j], maxDiff + prices[i]);
            }
        }
        
        return dp[prices.size() - 1][2];
    }
};