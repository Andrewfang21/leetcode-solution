class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> left, right, count;
        int degree = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (left.find(nums[i]) == left.end())
                left[nums[i]] = i;
            
            right[nums[i]] = i;
            count[nums[i]] ++;
            degree = max(degree, count[nums[i]]);
        }
        
        int shortest = INT_MAX;
        for (const auto &c : count) {
            if (c.second == degree)
                shortest = min(shortest, right[c.first] - left[c.first] + 1);
        }
        
        return shortest;
    }
};
