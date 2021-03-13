class Solution {
public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        for (int bit = 0; bit < 32; bit ++) {
            if ((n & (1 << bit)) != 0)
                total ++;
        }
        return total;
    }
};