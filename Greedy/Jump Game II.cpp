class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int curr = 0, next = 0;
        
        for (int i = 0; i != nums.size() - 1; i ++) {
            next = max(next, i + nums[i]);
            if (curr == i) {
                res ++;
                curr = next;
            }
        }
        return res;
    }
};