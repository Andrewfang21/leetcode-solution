class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> occur;
        for (char c : s)
            occur[c] ++;
        
        int maxOdd = 0;
        char cOdd;
        for (const auto &it : occur) {
            if (it.second % 2) {
                if (maxOdd < it.second) {
                    maxOdd = it.second;
                    cOdd = it.first;
                }
            }
        }
    
        int res = 0;
        for (const auto &it : occur) {
            if (it.second % 2) {
                if (it.first == cOdd)   res += it.second;
                else res += (it.second - 1);
            } else res += it.second;
        }
        
        return res;
    }
};