class Solution {
public:
    static bool cmp(const vector<int>& x, const vector<int>& y) {
        return x[0] < y[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i ++) {
            if (res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        return res;
    }
};