class Solution {
public:
    int kadane(vector<int> array, int K) {
        int currSum = 0;
        int currMax = INT_MIN;
        set<int> st;
        st.insert(0);
        
        for (int num : array) {
            currSum += num;
            auto it = st.lower_bound(currSum - K);
            if (it != st.end()) {
                currMax = max(currMax, currSum - *it);
            }
            
            st.insert(currSum);
        }
        return currMax;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        if (matrix.empty())
            return 0;
        
        int maxSum = INT_MIN;
        for (int i = 0; i < matrix[0].size(); i ++) {
            vector<int> sum(matrix.size());
            for (int j = i; j < matrix[0].size(); j ++) {
                for (int k = 0; k < matrix.size(); k ++)
                    sum[k] += matrix[k][j];
                
                int currMax = kadane(sum, K);
                maxSum = max(maxSum, currMax);
            }
        }
        
        return maxSum;
    }
};