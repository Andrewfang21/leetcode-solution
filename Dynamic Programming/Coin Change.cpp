class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long dp[amount + 5];
        for (int i = 1; i <= amount; i ++)
            dp[i] = INT_MAX;
        dp[0] = 0;
        for (int i = 0; i <= amount; i ++) {
            for (int coin : coins) {
                if (coin > i)
                    continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};