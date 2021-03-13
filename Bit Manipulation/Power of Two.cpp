class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;
        
        bool hasActiveBit = false;
        for (int bit = 0; bit < 32; bit ++) {
            if ((n & (1 << bit)) != 0) {
                if (!hasActiveBit)
                    hasActiveBit = true;
                else return false;
            }
        }
        return hasActiveBit;
    }
};