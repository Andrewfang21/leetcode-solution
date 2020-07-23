class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> q;
        for (int num : nums)
            q.push(num);
            
        int res;
        while (k --) {
            res = q.top();
            q.pop();
        }
        return res;
    }
};