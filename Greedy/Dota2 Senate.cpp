class Solution {
public:
    string predictPartyVictory(string senate) {
        int blockR = 0,
            blockD = 0;
        int sumR = 0,
            sumD = 0;

        for (char s : senate) {
            if (s == 'R')   sumR ++;
            else sumD ++;
        }

        while (sumR && sumD) {
            for (int i = 0; i < senate.length(); i ++) {
                if (blockR && senate[i] == 'R') {
                    blockR --;
                    sumR --;
                    senate[i] = ' ';
                } else if (blockD && senate[i] == 'D') {
                    blockD --;
                    sumD --;
                    senate[i] = ' ';
                } else if (senate[i] == 'R')
                    blockD ++;
                else if (senate[i] == 'D') 
                    blockR ++;
            }
        }

        return (sumD > 0) ? "Dire" : "Radiant";
    }
};