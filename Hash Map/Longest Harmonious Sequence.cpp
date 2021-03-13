class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> cnt;
        for (int n : nums)
            cnt[n] ++;
        
        int res = 0;
        for (int n : nums) {
            res = max(res, cnt[n + 1] == 0 ? 0 : cnt[n] + cnt[n + 1]);
        }
        return res;
    }
};