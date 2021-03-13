class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for (int num : nums)
            bitmask ^= num;
        
        int diff = 0;
        for (int i = 0; i < 32; i ++) {
            if ((bitmask & (1 << i)) != 0) {
                diff = i;
                break;
            }
        }
        
        vector<int> answer(2);
        for (int num : nums) {
            if ((num & (1 << diff)) != 0)
                answer[0] ^= num;
            else answer[1] ^= num;
        }
        
        return answer;
    }
};