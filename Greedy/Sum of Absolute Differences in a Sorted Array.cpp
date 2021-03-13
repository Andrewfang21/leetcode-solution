class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefSum(n, 0);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i ++)
            prefSum[i] = prefSum[i - 1] + nums[i];
        
        vector<int> sumAbsoluteDifferences(n, 0);
        for (int i = 0; i < n; i ++) {
            int leftSum = 0, rightSum = 0;
            if (i > 0)
                leftSum = nums[i] * i - prefSum[i - 1];
            if (i < n)
                rightSum = (prefSum[n - 1] - prefSum[i]) - nums[i] * (n - i - 1);
            
            sumAbsoluteDifferences[i] = leftSum + rightSum;
        }
        
        return sumAbsoluteDifferences;
    }
};