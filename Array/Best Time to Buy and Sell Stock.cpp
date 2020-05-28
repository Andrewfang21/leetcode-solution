class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        
        int left[n + 5], right[n + 5];
        
        left[0] = prices[0];
        for (int i = 1; i < n; i ++)
            left[i] = min(left[i - 1], prices[i]);
        
        right[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i --)
            right[i] = max(right[i + 1], prices[i]);
        
        int res = 0;
        for (int i = 0; i < n; i ++)
            res = max(res, right[i] - left[i]);
        
        return res;
    }
};