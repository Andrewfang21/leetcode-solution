class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); i ++)
                if (nums[i] <= mid)
                    count ++;
            if (count > mid)
                r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};