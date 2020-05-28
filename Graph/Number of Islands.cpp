const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int n, m;
    
    bool inside(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j ]== '0')
            return;
    
        grid[i][j] = '0';
        for (int k = 0; k < 4; k ++) {
            int x = i + dx[k];
            int y = j + dy[k];
    
            if (inside(x, y))
                dfs(grid, x, y);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0)
            return 0;
        m = grid[0].size();

        int res = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j]=='1') {
                    dfs(grid, i, j);
                    res ++;
                }
            }
        }
        return res;
    }
};
