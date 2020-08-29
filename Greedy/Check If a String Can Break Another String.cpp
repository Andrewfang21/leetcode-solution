class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        
        bool res1, res2;
        res1 = res2 = true;
        for (int i = s1.length() - 1; i >= 0; i --) {
            if (s1[i] < s2[i])
                res1 = false;
            if (s2[i] < s1[i])
                res2 = false;
        }
        return res1 || res2;
    }
};