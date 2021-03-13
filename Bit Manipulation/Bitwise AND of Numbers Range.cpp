class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int rangeBitwise = 0;
        for (int bit = 30; bit >= 0; bit --) {
            if ((left & (1 << bit)) != (right & (1 << bit)))
                break;
            rangeBitwise |= (right & (1 << bit));
        }
        
        return rangeBitwise;
    }
};