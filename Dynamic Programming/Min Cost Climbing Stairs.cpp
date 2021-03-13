class Solution {
public:
    int solve(int pos, int dp[1005], vector<int> &cost) {
        if (pos >= cost.size()) return 0;
        if (dp[pos] != -1)  return dp[pos];
        
        int res = cost[pos] + min(solve(pos + 1, dp, cost), solve(pos + 2, dp, cost));
        return dp[pos] = res;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1005];
        memset(dp, -1, sizeof(dp));
        
        return min(solve(0, dp, cost), solve(1, dp, cost));
    }
};