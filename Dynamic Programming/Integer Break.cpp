class Solution {
public:
    int solve(int pos, int dp[60]) {
        if (dp[pos] != -1)
            return dp[pos];
        
        int res = pos;
        for (int i = 1; i < pos; i ++) {
            int curr = i * solve(pos - i, dp);
            if (res < curr)
                res = curr;
        }
        return dp[pos] = res;
    }
    
    int integerBreak(int n) {
        int res = INT_MIN;
        int dp[60];
        memset(dp, -1, sizeof(dp));
        
        for (int i = 1; i < n; i ++) {
            int curr = solve(i, dp) * solve(n - i, dp);
            if (curr > res)
                res = curr;
        }
        return res;
    }
};