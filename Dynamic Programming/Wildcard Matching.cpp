class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        int dp[n + 5][m + 5];
        memset(dp, false, sizeof(dp));

        dp[0][0] = true;
        for (int i = 1; i <= m; i ++)
            dp[0][i] = p[i - 1] == '*' ? dp[0][i - 1] : false;

        for (int j = 1; j <= m; j ++) {
            for (int i = 1; i <= n; i ++) {
                if (p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = s[i - 1] == p[j - 1] && dp[i - 1][j - 1];
            }   
        }
        
        return dp[n][m];
    }
};