class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1, m2;
        for (int n : nums1)     m1[n] ++;
        for (int n : nums2)     m2[n] ++;
        
        vector<int> results;
        for (const auto &r : m1) {
            int cnt = min(m1[r.first], m2[r.first]);
            for (int i = 0; i < cnt; i ++)
                results.push_back(r.first);
        }
        
        return results;
    }
};