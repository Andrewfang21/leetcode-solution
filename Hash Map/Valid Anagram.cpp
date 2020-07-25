class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        map<char, int> store[2];
        for (char c : s)
            store[0][c] ++;
        for (char c : t)
            store[1][c] ++;
        
        for (const auto &it : store[0]) {
            if (store[0][it.first] != store[1][it.first])
                return false;
        }
        return true;
    }
};