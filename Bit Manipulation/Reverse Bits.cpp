class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversedBits = 0;
        for (int i = 0; i < 32; i ++) {
            int bit = min((n & (1 << (32 - i - 1))), (uint32_t) 1);
            reversedBits |= (bit << i);
        }
        return reversedBits;
    }
};