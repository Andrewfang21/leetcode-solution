class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                i --;
            }
        }
                
        vector<int> answer;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] != i + 1)
                answer.push_back(nums[i]);
        }
        
        return answer;
    }
};
