class Solution {
public:
    string getHint(string secret, string guess) {
        int correctPos = 0, correctChar = 0;
        map<char, int> msecret, mguess;
        for (int i = 0; i < secret.length(); i ++) {
            msecret[secret[i]] ++;
            mguess[guess[i]] ++;
        }
        for (const auto &it : mguess) {
            correctChar += min(msecret[it.first], it.second);
        }
        for (int i = 0; i < secret.length(); i ++) {
            if (secret[i] == guess[i]) {
                correctPos ++;
                correctChar --;   
            }            
        }
        
        char res[1005];
        sprintf(res, "%dA%dB", correctPos, correctChar);
        return res;
    }
};