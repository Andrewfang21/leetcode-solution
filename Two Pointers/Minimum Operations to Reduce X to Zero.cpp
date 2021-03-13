class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int targetSum = 0;
        for (int num : nums)    targetSum += num;
        targetSum -= x;
        
        if (targetSum < 0)
            return -1;
        
        int l = 0, r = 0;
        int sum = 0;
        int minOp = INT_MAX;
        while (r < nums.size()) {
            while (sum <= targetSum && r < nums.size()) {
                sum += nums[r];
                r ++;
                if (sum == targetSum)
                    minOp = min(minOp, (int) nums.size() - r + l);
            }

            while (sum >= targetSum && l < r) {
                sum -= nums[l];
                l ++;
                if (sum == targetSum)
                    minOp = min(minOp, (int) nums.size() - r + l);
            }
        }
        
        return minOp == INT_MAX ? -1 : minOp;
    }
};