class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        priority_queue<int> q;
        for (int i = 0; i < m; i ++)
            q.push(mat[0][i]);
        
        for (int i = 1; i < n; i ++) {
            priority_queue<int> backup;
            while (!q.empty()) {
                int curr = q.top();
                q.pop();
                
                for (int j = 0; j < m; j ++) {
                    int sum = curr + mat[i][j];
                    if (backup.size() < k)
                        backup.push(sum);
                    else {
                        if (backup.top() > sum) {
                            backup.pop();
                            backup.push(sum);
                        }
                    }
                }
            }
            q = backup;
        }
        
        return q.top();
    }
};