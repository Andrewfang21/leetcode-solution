class Solution {
public:
    string removeKdigits(string num, int k) {
        int length = num.length();
        if (length <= k)
            return "0";
        
        int remaining = length - k;
        string res = "";
        for (char c : num) {
            while (k > 0 && !res.empty() && res.back() > c) {
                res.pop_back();
                k --;
            }
            res.push_back(c);
        }
        
        res.resize(remaining);
        while (!res.empty() && res[0] == '0')
            res.erase(res.begin());
        
        return res.empty() ? "0" : res;
    }
};