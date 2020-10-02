class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[l] == target)
                return true;
            else if (nums[r] == target)
                return true;
            else if (target > nums[mid] && target < nums[r])
                l = mid + 1;
            else if (target < nums[mid] && target > nums[l])
                r = mid - 1;
            else {
                l ++;
                r --;
            }
        }
        
        return false;      
    }
};
