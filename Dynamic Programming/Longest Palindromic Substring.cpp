class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;
        
        int n = s.length();
        bool dp[n + 5][n + 5];
        memset(dp, false, sizeof(dp));
        
        for (int i = 0; i < n; i ++)
            dp[i][i] = true;
        
        string res = s.substr(0, 1);
        for (int len = 2; len <= n; len ++)
            for (int i = 0; i < n - len + 1; i ++) {
                int j = i + len - 1;
                if (s[i] == s[j] && i != j) {
                    if (j == i + 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && (j - i + 1) > res.length())
                    res = s.substr(i, j - i + 1);
            }
        
        return res;
    }
};