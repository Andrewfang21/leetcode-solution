class Solution {
public:
     bool isPossible(int target, vector<int> &nums, int m) {
        int partition = 1;
        int sum = 0;
        for (int num : nums) {
            if (num > target)
                return false;
            
            if (sum + num <= target)
                sum += num;
            else if (sum + num > target) {
                partition ++;
                sum = num;
            }
        }
        
        return partition <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int maxPossible = 0, minPossible = INT_MAX;
        for (int num : nums) {
            maxPossible += num;
            minPossible = min(minPossible, num);
        }
        
        int l = minPossible, r = maxPossible;
        int res = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isPossible(mid, nums, m)) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        
        return res;
    }
};