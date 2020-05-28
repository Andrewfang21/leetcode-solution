class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = 0;
        int globalMax = INT_MIN;
        
        for (int num : nums) {
            currMax += num;
            if (currMax > globalMax)
                globalMax = currMax;
            
            if (currMax < 0)
                currMax = 0;
        }
        
        return globalMax;
    }
};