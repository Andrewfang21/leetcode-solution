class NumMatrix {
public:
    int pref[1005][1005];
    NumMatrix(vector<vector<int>>& matrix) {
        memset(pref, 0, sizeof(pref));
        int n, m;
        n = matrix.size();
        if (n == 0)
            return;
        m = matrix[0].size();
        
        pref[1][1] = matrix[0][0];
        for (int i = 2; i <= n; i ++)
            pref[i][1] = pref[i-1][1] + matrix[i-1][0];
        for (int j = 2; j <= m; j ++)
            pref[1][j] = pref[1][j-1] + matrix[0][j-1];
        
        for (int i = 2; i <= n; i ++)
            for (int j = 2; j <= m; j ++) {
                pref[i][j] = pref[i-1][j]  + pref[i][j-1] + matrix[i-1][j-1] - pref[i-1][j-1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pref[row2 + 1][col2 + 1] - pref[row1][col2 + 1] - pref[row2 + 1][col1] + pref[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */