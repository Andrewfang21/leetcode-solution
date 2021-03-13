class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        map<int,int> position;
        int totCount = 0;
        for (int i = 0; i < row.size(); i ++)
            position[row[i]] = i;
        
        for (int i = 0; i < row.size(); i += 2) {
            int currPerson = row[i];
            int couple;
            if (currPerson % 2 == 0)
                couple = currPerson + 1;
            else
                couple = currPerson - 1;
            
            if (row[i + 1] == couple)
                continue;
            
            swap(row[i + 1], row[position[couple]]);
            position[row[position[couple]]] = position[couple];
            totCount ++;
        }
        
        return totCount;
    }
};