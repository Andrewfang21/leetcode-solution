class Solution {
public:
    bool inside(int x, int y, vector<vector<int>> &grid) {
        return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size());
    }
    
    void dfs(int x, int y, int& res, vector<vector<int>>& grid, vector<vector<bool>> &visited) {
        if (!inside(x, y, grid) || visited[x][y] || grid[x][y] == 0)
            return;
        
        visited[x][y] = true;
        if (grid[x][y] == 1)
            res ++;
        
        dfs(x + 1, y, res, grid, visited);
        dfs(x - 1, y, res, grid, visited);
        dfs(x, y + 1, res, grid, visited);
        dfs(x, y - 1, res, grid, visited);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[i].size(); j ++) {
                if (!visited[i][j]) {
                    int currArea = 0;
                    dfs(i, j, currArea, grid, visited);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;
    }
};