class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int pos = 0;
        while (pos < heights.size()) {
            if (st.empty() || heights[st.top()] <= heights[pos]) {
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
};