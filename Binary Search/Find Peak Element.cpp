class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        
        int n = nums.size() - 1;
        
        int l = 0, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid == 0) {
                if (nums[mid + 1] < nums[mid]) 
                    return mid;
                else l = mid + 1;
            } else if (mid == n) {
                if (nums[mid - 1] < nums[mid]) 
                    return mid;
                else r = mid - 1;
            } else if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;
            else if (nums[mid + 1] > nums[mid - 1])
                l = mid + 1;
            else r = mid - 1;
        }
        return 0;
    }
};