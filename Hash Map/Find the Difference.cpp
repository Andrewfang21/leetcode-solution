class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> ms, mt;
        for (char c : s)
            ms[c] ++;
        for (char c : t)
            mt[c] ++;
        
        for (const auto &it : mt) {
            if (mt[it.first] != ms[it.first])
                return it.first;
        }
        
        return ' ';
    }
};