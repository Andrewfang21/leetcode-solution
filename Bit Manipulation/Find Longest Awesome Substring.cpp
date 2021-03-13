class Solution {
public:
    int longestAwesome(string s) {
        int longest = 0;
        vector<int> masks((1 << 10), INT_MAX);
        
        masks[0] = 0;
        int bitmasks = 0;
        for (int i = 0; i < s.length(); i ++) {
            bitmasks ^= (1 << (s[i] - '0'));
            masks[bitmasks] = min(masks[bitmasks], i);
            if (__builtin_popcount(bitmasks) <= 1)
                longest = i + 1;
            
            for (int bit = 0; bit < 10; bit ++) {
                int nextMask = bitmasks ^ (1 << bit);
                longest = max(longest, i - masks[nextMask]);
            }
        }
        
        return longest;
    }
};