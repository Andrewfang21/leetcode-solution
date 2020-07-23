class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        int i = 0;
        long long reachable = 1;
        while (reachable <= n) {
            if (i >= nums.size()) {
                reachable += reachable;
                res ++;
                
                continue;
            }
            if (reachable >= nums[i]) {
                reachable += nums[i];
                i ++;
            } else {
                reachable += reachable;
                res ++;
            }
        }
        return res;
    }
};