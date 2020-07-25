class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for (char c : s)
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
                temp += tolower(c);
            else continue;
        
        int l = 0;
        int r = temp.length() - 1;
        while (l <= r) {
            if (temp[l] == temp[r])
                l ++, r --;
            else return false;
        }
        return true;
    }
};