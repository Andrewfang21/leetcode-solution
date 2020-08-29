class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        int candies[n + 5];
        for (int i = 0; i < n; i ++)
            candies[i] = 1;
        
        int last = n - 1;
        for (int i = last - 1; i >= 0; i --) {
            if (ratings[i] > ratings[last])
                candies[i] = candies[last] + 1;
            last --;
        }
        for (int i = 0; i < n - 1; i ++) {
            if (ratings[i] < ratings[i + 1]) {
                if (candies[i] >= candies[i + 1])
                    candies[i + 1] = candies[i] + 1;
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; i ++)
            res += candies[i];

        return res;
    }
};