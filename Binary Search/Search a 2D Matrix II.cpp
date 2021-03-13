class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i ++) {
            if (matrix[i][0] > target)
                break;
            
            int l = 0, r = m - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (matrix[i][m] == target)
                    return true;
                else if (matrix[i][m] < target)
                    l = m + 1;
                else r = m - 1;
            }
        }
        
        return false;
    }
};