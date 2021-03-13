class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' || 
                c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O');
    }
    
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        int n = s.length();
        while (l < r && l < n && r < n) {
            while (!isVowel(s[l]) && l < n)
                l ++;
            while (!isVowel(s[r]) && r > 0)
                r --;
                        
            if (l < r && isVowel(s[l]) && isVowel(s[r])) {
                swap(s[l], s[r]);
                l ++, r --;
            }
        }
        
        return s;
    }
};