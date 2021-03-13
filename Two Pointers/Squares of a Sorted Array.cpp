class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> sorted;
        vector<int> neg, pos;
        for (int num : A) {
            if (num < 0)    neg.push_back(num * num);
            else pos.push_back(num * num);
        }
        
        int i = neg.size() - 1, j = 0;
        while (i >= 0 && j < pos.size()) {
            if (neg[i] < pos[j]) {
                sorted.push_back(neg[i --]);
            } else {
                sorted.push_back(pos[j ++]);
            }
        }
        
        while (i >= 0)   sorted.push_back(neg[i --]);
        while (j < pos.size())  sorted.push_back(pos[j ++]);
        
        return sorted;
    }
};