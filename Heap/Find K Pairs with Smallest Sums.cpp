class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty())
            return res;
        
        typedef pair<int, pair<int, int>> ii;
        priority_queue<ii, vector<ii>, greater<ii>> q;
        for (int i = 0; i < nums1.size(); i ++) {
            int num1 = nums1[i];
            for (int j = 0; j < nums2.size(); j ++) {                
                int num2 = nums2[j];
                q.push(make_pair(num1 + num2, make_pair(num1, num2)));
            }
        }
        
        for (int i = 0; i < k; i ++) {
            vector<int> temp;
            ii curr = q.top();
            q.pop();
            
            temp.push_back(curr.second.first);
            temp.push_back(curr.second.second);
            res.push_back(temp);
            
            if (q.empty())
                break;
        }
        return res;
    }
};
