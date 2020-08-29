class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [&](vector<int> x, vector<int> y) {
            return (x[0] - y[0] > x[1] - y[1]);
        });
        
        int res = 0;
        for (int i = 0; i < costs.size(); i ++) {
            res += (i < costs.size() / 2)
                ? costs[i][1]
                : costs[i][0];
        }
        return res;
    }
};