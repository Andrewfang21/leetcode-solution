class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n, m;
        n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        int dp[105][105];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 1; i < n; i ++) {
            if (obstacleGrid[i][0] == 1)    break;
            dp[i][0] = dp[i - 1][0];
        }
            
        for (int j = 1; j < m; j ++) {
            if (obstacleGrid[0][j] == 1)    break;            
            dp[0][j] = dp[0][j - 1];
        }
        
        for (int i = 1; i < n; i ++)
            for (int j = 1; j < m; j ++)
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
                
        return dp[n - 1][m - 1];
    }
};