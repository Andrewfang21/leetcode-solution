class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        unordered_map<long long, long long> sumStorage;
        long long prefSum = 0;

        int countRange = 0;
        // O(n^2) -- A better solution is O(nlgn) with segment tree or BIT         
        for (int num : nums) {
            prefSum += num;
            
            for (long long i = lower; i <= upper; i ++) {
                if (prefSum == i)
                    countRange ++;
                auto it = sumStorage.find(prefSum - i);
                if (it != sumStorage.end()) {
                    countRange += it->second;
                }
            }
            sumStorage[prefSum] ++;
        }
        
        return countRange;
    }
};