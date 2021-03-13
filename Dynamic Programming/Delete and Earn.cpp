class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(1e4 + 5, 0);
        vector<int> cnt(1e4 + 5, 0);
        for (int num : nums)
            cnt[num] ++;
        
        dp[0] = 0;
        dp[1] = cnt[1];
        for (int i = 2; i < 1e4 + 5; i ++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
        }
        
        int res = INT_MIN;
        for (int d : dp)    res = max(res, d);
        
        return res;
    }
};