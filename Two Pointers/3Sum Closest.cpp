class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int currClosest = nums[0] + nums[1] + nums[2];
        if (nums.size() == 3)
            return currClosest;
            
        for (int i = 0; i < nums.size() - 2; i ++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int currDistance = target - sum;
                if (currDistance == 0)
                    return target;
                else if (currDistance > 0) {
                    if (abs(currDistance) < abs(target - currClosest))
                        currClosest = sum;
                    l ++;
                } else {
                    if (abs(currDistance) < abs(target - currClosest))
                        currClosest = sum;
                    r --;
                }
            }
        }
        
        return currClosest;
    }
};