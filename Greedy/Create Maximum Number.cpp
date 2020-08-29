class Solution {
public:
    vector<int> getGreatest(vector<int> nums, int k) {
        vector<int> res(k, 0);
        for (int i = 0, j = 0; i < nums.size(); i ++) {
            while (nums.size() - i + j > k && j > 0 && res[j - 1] < nums[i])
                j --;
            if (j < k) {
                res[j ++] = nums[i];
            }
        }
        return res;
    }
    
    bool isGreater(vector<int> nums1, vector<int> nums2, int i, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
            i ++, j ++;
        }
        return (j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]));
    }
    
    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> res(k, 0);
        for (int i = 0, j = 0, l = 0; l < k; l ++) {
            res[l] = isGreater(nums1, nums2, i, j) ? nums1[i ++] : nums2[j ++];
        }
        return res;
    }
        
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        for (int i = 0; i <= k; i ++) {
            if (i > nums1.size() || (k - i) > nums2.size())
                continue;
            
            vector<int> first = getGreatest(nums1, i);
            vector<int> second = getGreatest(nums2, k - i);                
            vector<int> curr = merge(first, second, k);
            
            if (isGreater(curr, res, 0, 0))
                res = curr;
        }
        return res;
    }
};