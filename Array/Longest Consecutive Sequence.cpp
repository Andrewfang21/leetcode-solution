class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        unordered_map<int,bool> uniqueNums;
        for (int num : nums)
            uniqueNums[num] = true;
        
        int longest = 0;
        unordered_map<int,int> storage;
        for (int num : nums) {
            if (uniqueNums.find(num - 1) == uniqueNums.end()) {
                int currLongest = 0;
                while (uniqueNums.find(num) != uniqueNums.end()) {
                    num ++;
                    currLongest ++;
                }
                longest = max(longest, currLongest);
            }
        }
        
        return longest;
    }
};