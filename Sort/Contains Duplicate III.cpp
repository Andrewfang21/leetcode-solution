class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> numCollection;
        int left = 0;
        for (int right = 0; right < nums.size(); right ++) {
            if (right - left > k)
                numCollection.erase(nums[left ++]);
            
            long long lower = (long long) nums[right] - t;
            long long upper = (long long) nums[right] + t;            
            auto it = numCollection.lower_bound(lower);
            
            if (it != numCollection.end() && *it <= upper)
                return true;
            
            numCollection.insert(nums[right]);
        }
        
        return false;
    }
};
