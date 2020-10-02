class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int sum = 0;
        for (char c : s) {
            if (c == 'R')
                sum ++;
            else
                sum --;
            
            if (sum == 0)
                res ++;
        }
        
        return res;
    }
};
