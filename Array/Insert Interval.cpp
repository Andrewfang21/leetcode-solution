class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.empty())
            return vector<vector<int>>{newInterval};

        int pos = 0;
        while (pos < intervals.size() && intervals[pos][0] < newInterval[0])
            res.push_back(intervals[pos ++]);
        if (res.empty() || res.back()[1] < newInterval[0])
            res.push_back(newInterval);
        else res.back()[1] = max(res.back()[1], newInterval[1]);
        
        while (pos < intervals.size() && res.back()[1] >= intervals[pos][0])
            res.back()[1] = max(res.back()[1], intervals[pos ++][1]);
        while (pos < intervals.size())
            res.push_back(intervals[pos ++]);
        
        return res;
    }
};