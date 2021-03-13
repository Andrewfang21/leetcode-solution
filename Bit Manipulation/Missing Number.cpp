class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int bitmask = nums.size();
        for (int i = 0; i < nums.size(); i ++) {
            bitmask ^= (i ^ nums[i]);
        }
        return bitmask;
    }
};