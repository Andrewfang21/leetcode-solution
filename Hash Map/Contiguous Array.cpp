class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        map<int, int> store;
        
        for (int i = 0; i < nums.size(); i ++) {
            sum += (nums[i] == 0) ? -1 : 1;
            if (store.find(sum) != store.end())
                res = max(res, i - store[sum]);
            else
                store[sum] = i;
            
            if (sum == 0)
                res = i + 1;
        }
        return res;
    }
};