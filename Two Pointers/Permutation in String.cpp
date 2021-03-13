class Solution {
public:
    bool isEqual(map<char, int> m1, map<char, int> m2) {
        bool ret = true;
        for (const auto &it : m1) {
            if (m1[ it.first ] <= m2[ it.first ])
                continue;
            else return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        
        map<char, int> m1, m2;
        for (char c : s1)   m1[c] ++;
        
        int l = 0, r = 0;
        int n = s2.length();
        int m = s1.length();
        m2[ s2[0] ] ++;
        while (r < n) {
            while (r - l + 1 < m) {
                r ++;
                m2[ s2[r] ] ++;
            }
            if (isEqual(m1, m2))
                return true;               

            m2[ s2[l] ] --;
            l ++;
        }
        return false;
    }
};