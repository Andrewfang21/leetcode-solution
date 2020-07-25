class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> store;
        for (int num : nums1)
            store[num] = true;
    
        vector<int> res;
        for (int num : nums2) {
            if (store.find(num) != store.end())
                res.push_back(num);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};