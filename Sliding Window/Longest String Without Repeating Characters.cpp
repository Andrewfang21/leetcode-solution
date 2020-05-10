class Solution {
public:
    map<char, int> occur;

    int lengthOfLongestSubstring(string s) {
        occur.clear();
        
        int l, r;
        l = r = 0;
        
        int res = 0;
        while (r < s.length()) {
            occur[s[r]] ++;
            while (occur[ s[r] ] > 1) {
                occur[ s[l] ] --;
                l ++;
            }
            
            res = max(res, r - l + 1);
            r ++;
        }
        
        return res;
    }
};