class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mapper;
        map<char, char> demapper;
        for (int i = 0; i < s.length(); i ++) {
            if (mapper.find(s[i]) != mapper.end()) {
                if (mapper[s[i]] == t[i] && demapper[t[i]] == s[i])
                    continue;
                return false;
            } else if (demapper.find(t[i]) != demapper.end()) {
                if (demapper[t[i]] == s[i] && demapper[s[i]] == t[i])
                    continue;
                return false;
            } else {
                mapper[s[i]] = t[i];
                demapper[t[i]] = s[i];
            }
        }
        return true;
    }
};
