class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (int num : nums)
            freq[num] ++;
        
        typedef pair<int, int> ii;
        priority_queue<ii, vector<ii>> q;
        for (const auto &it : freq)
            q.push(make_pair(it.second, it.first));
        
        vector<int> v;
        while (k --) {
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};
