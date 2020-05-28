class Solution {
public:
    int subarrayWithAtMostKDistinct(vector<int>& A, int K) {
        int l = 0, r = 0;
        int res = 0;
        int n = A.size();
        
        map<int, int> exist;
        while (r < n) {
            if (exist.find(A[r]) == exist.end())
                exist[ A[r] ] = 0;
            exist[ A[r] ] ++;
            
            while (exist.size() > K) {
                exist[ A[l] ] --;
                if (exist[ A[l] ] == 0)
                    exist.erase(A[l]);
                
                l ++;
            }
            
            res += (r - l + 1);
            r ++;
        }
        
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return subarrayWithAtMostKDistinct(A, K) - 
               subarrayWithAtMostKDistinct(A, K - 1);
    }
};