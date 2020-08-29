class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return 0;
        
        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) {
            return x[1] < y[1];
        });
        
        int res = 0;
        for (int i = 0; i < intervals.size() - 1; i ++) {
            bool isOverlap = intervals[i][1] > intervals[i + 1][0] ? true : false;
            if (isOverlap) {
                res ++;
                if (intervals[i][1] < intervals[i + 1][1])
                    intervals[i + 1] = intervals[i];
            }
        }
        return res;
    }
};