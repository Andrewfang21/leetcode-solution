class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r = 0;
        int res = 0;
        
        int zeroCount = 0;
        while (r < A.size()) {
            if (A[r] == 0)
                zeroCount ++;
            while (zeroCount > K) {
                if (A[l] == 0)
                    zeroCount --;
                l ++;
            }
            
            res = max(res, r - l + 1);
            r ++;
        }
        
        return res;
    }
};