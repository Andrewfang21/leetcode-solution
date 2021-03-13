class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int l = 0, r = 0;
        int res = 0;
        sort(points.begin(), points.end());
        
        while (r < points.size()) {
            r ++;
            while (r < points.size() && points[l][1] >= points[r][0]) {
                if (points[l][1] > points[r][1])
                    points[l][1] = points[r][1];
                r ++;
            }
            res ++;
            l = r;
        }
        
        return res;
    }
};