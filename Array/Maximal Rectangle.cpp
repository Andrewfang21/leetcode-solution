class Solution {
public:
    int maximalHistogram(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int pos = 0;
        
        while (pos < heights.size()) {
            if (st.empty() || heights[pos] >= heights[st.top()]) {
                st.push(pos);
                pos ++;
            } else {
                int lastIndex = st.top();
                st.pop();
                int currArea = heights[lastIndex] * (st.empty() ? pos : pos - st.top() - 1);
                maxArea = max(maxArea, currArea);
            }
        }
        
        while (!st.empty()) {
            int lastIndex = st.top();
            st.pop();
            int currArea = heights[lastIndex] * (st.empty() ? pos : pos - st.top() - 1);
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        
        vector<vector<int>> maze;
        for (int i = 0; i < matrix.size(); i ++) {
            maze.push_back(vector<int>());
            for (int j = 0; j < matrix[i].size(); j ++)\
                maze.back().push_back(matrix[i][j] - '0');
        }
        
        int maxArea = maximalHistogram(maze[0]);
        for (int i = 1; i < maze.size(); i ++) {
            for (int j = 0; j < maze[i].size(); j ++) {
                if (maze[i][j])
                    maze[i][j] += maze[i - 1][j];
            }
            int currArea = maximalHistogram(maze[i]);
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
};