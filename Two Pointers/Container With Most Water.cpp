class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maximumArea = 0;
        
        while (l < r) {
            int currArea = (r - l) * min(height[l], height[r]);
            maximumArea = max(maximumArea, currArea);
            
            if (height[r] <= height[l])
                r --;
            else l ++;
        }
        
        return maximumArea;
    }
};