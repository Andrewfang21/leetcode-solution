class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> vis(26, false);
        vector<int> cnt(26, 0);
        
        string res = "";
        for (char c : s)
            cnt[c - 'a'] ++;
        
        for (char c : s) {
            cnt[c - 'a'] --;
            if (vis[c - 'a'])
                continue;
            
            while (!res.empty() && c < res.back() && cnt[res.back() - 'a'] > 0) {
                vis[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            vis[c - 'a'] = true;
        }
        return res;
    }
};