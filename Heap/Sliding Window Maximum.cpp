class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> v;
        int pos = 0;
        while (pos < k) {
            while (!q.empty() && nums[pos] >= nums[q.back()])
                q.pop_back();
            q.push_back(pos ++);
        }
        int n = nums.size();
        while (pos < n) {
            v.push_back(nums[q.front()]);
            while (!q.empty() && q.front() <= pos - k)
                q.pop_front();
            while (!q.empty() && nums[pos] >= nums[q.back()])
                q.pop_back();
            q.push_back(pos ++);
        }
        v.push_back(nums[q.front()]);
        return v;
    }
};