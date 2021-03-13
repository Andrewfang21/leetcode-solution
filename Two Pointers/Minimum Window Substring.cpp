class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";
        
        map<char, int> ms, mt;
        for (char c : t)    mt[c] ++;
        
        int res = 0, l = 0;
        int pos = -1;
        int minLen = INT_MAX;
        for (int r = 0; r < s.length(); r ++) {
            ms[ s[r] ] ++;
            if (mt[ s[r] ] != 0 && ms[ s[r] ] <= mt[ s[r] ])
                res ++;
            if (res == t.length()) {
                while(mt[ s[l] ] == 0 || ms[ s[l] ] > mt[ s[l] ]) {
                    ms[ s[l] ] --;
                    l ++;
                }
                
                int sz = r - l + 1;
                if (sz < minLen) {
                    minLen = sz;
                    pos = l;
                }
            }
        }
        
        if (pos == -1)
            return "";
        else
            return s.substr(pos, minLen);
    }
};