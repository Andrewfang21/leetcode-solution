class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int withStock = -prices[0], withoutStock = 0;
        for (int i = 1; i < prices.size(); i ++) {
            withoutStock = max(withoutStock, withStock + prices[i] - fee);
            withStock = max(withStock, withoutStock - prices[i]);
        }
        
        return withoutStock;
    }
};
