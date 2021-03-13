class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size()), suff(nums.size());
        for (int i = 0; i < nums.size(); i ++) {
            pref[i] = (i == 0) ? nums[i] : pref[i - 1] * nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i --) {
            suff[i] = (i == nums.size() - 1) ? nums[i] : suff[i + 1] * nums[i];
        }
        
        vector<int> answer;
        for (int i = 0; i < nums.size(); i ++) {
            int left = (i == 0) ? 1 : pref[i - 1];
            int right = (i == nums.size() - 1) ? 1 : suff[i + 1];
            answer.push_back(left * right);
        }
        
        return answer;
    }
};