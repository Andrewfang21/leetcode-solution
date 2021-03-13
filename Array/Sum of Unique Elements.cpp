class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int, int> store;
        for (int n : nums)
            store[n] ++;
        
        int res = 0;
        for (const auto &num : store)
            if (num.second == 1)
                res += num.first;
        
        return res;
    }
};