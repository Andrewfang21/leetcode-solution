class NumArray {
public:
    int pref[10000005];
    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++)
            pref[i] = i == 0 ? nums[i] : pref[i - 1] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? pref[j] : pref[j] - pref[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
