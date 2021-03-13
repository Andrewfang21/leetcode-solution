class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;
        
        if (n == 0) {
            return 0;
        }
        
        int res = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int sum = 0;
            bool can = false;
            for (int ll = 0, rr = mid - 1; rr < n; rr ++) {
                if (ll == 0) {
                    for (int j = ll; j <= rr; j ++)
                        sum += nums[j];
                } else sum += nums[rr];
                
                if (sum >= s) {
                    can = true;
                    break;
                }
                
                sum -= nums[ll ++];
            }
            
            if (can) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return res;
    }
};