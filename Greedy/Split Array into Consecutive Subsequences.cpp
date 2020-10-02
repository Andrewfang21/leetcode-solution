class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> counts, last;
        for (int num : nums)
            counts[num] ++;
        
        for (int num : nums) {
            if (counts[num] == 0)
                continue;
            counts[num] --;
            
            if (last[num - 1] > 0) {
                last[num - 1] --;
                last[num] ++;
            
            } else if (counts[num + 1] > 0 && counts[num + 2]) {
                counts[num + 1] --;
                counts[num + 2] --;
                last[num + 2] ++;
            
            } else return false; 
        }
        return true;
    }
};
