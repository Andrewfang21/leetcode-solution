class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int up = -1, low = -1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                low = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        
        l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) {
                up = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        
        vector<int> vec;
        if (up != -1 && low !=- 1 && nums[up] == target) {
            vec.push_back(low);
            vec.push_back(up);
        } else {
            vec.push_back(-1);
            vec.push_back(-1);
        }
        return vec;
    }
};