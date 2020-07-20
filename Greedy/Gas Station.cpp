class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, rem = 0;
        int pos = 0;
        
        for (int i = 0; i < gas.size(); i ++) {
            int diff = gas[i] - cost[i];
            total += diff;
            rem += diff;
            
            if (rem < 0) {
                rem = 0;
                pos = i + 1;
            }
        }
        
        if (total < 0)
            return -1;
        return pos;
    }
};