class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> totalBits(32);
        for (int num : nums) {
            for (int bit = 0; bit < 32; bit ++) {
                int isOn = (num & (1 << bit));
                if (isOn != 0) {
                    totalBits[bit] ++;
                }
            }
        }
        
        int totalNums = nums.size();
        int answer = 0;
        for (int bit : totalBits) {
            answer += bit * (totalNums - bit);
        }
        return answer;
    }
};