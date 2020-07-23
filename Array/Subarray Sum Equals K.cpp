class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> currSum;
        int sum = 0;
        int res = 0;
        for (int num : nums) {
            sum += num;
            if (sum == k)
                res ++;
            if (currSum.find(sum - k) != currSum.end())
                res += currSum[sum - k];
            currSum[sum] ++;
        }
        
        return res;
    }
};