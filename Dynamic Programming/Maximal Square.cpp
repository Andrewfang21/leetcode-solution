class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size(), width = matrix[0].size();
        vector<vector<int>> dp(height, vector<int>(width));
        
        int maximalSquare = 0;
        for (int i = 0; i < height; i ++) {
            for (int j = 0; j < width; j ++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0)
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    
                    maximalSquare = max(maximalSquare, dp[i][j]);
                }
            }
        }
        
        return maximalSquare * maximalSquare;
    }
};