class Solution {
public:
    int dp[50];
    
    int solve(int pos) {
        if (pos < 0)    return 0;
        if (pos == 0)   return 1;
        if (dp[pos] != -1)  return dp[pos];
        
        return dp[pos] = solve(pos - 1) + solve(pos - 2);
    }
    
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        int res = solve(n);
        
        return res;
    }
};