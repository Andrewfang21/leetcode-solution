class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        for (int i = 0; i < A.size(); i ++)
            if (A[i] == B[0])
                dp[i][0] = 1;
        for (int i = 0; i < B.size(); i ++)
            if (A[0] == B[i])
                dp[0][i] = 1;
        
        int answer = 0;
        for (int i = 1; i < A.size(); i ++) {
            for (int j = 1; j < B.size(); j ++) {
                if (A[i] == B[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                
                answer = max(answer, dp[i][j]);
            }
        }
        
        return answer;
    }
};
