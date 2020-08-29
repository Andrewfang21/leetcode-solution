class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](vector<int> x, vector<int> y) {
            return (x[0] == y[0] ? x[1] < y[1] : x[0] >= y[0]);
        });
        
        for (int i = 0; i < people.size(); i ++) {
            int currPos = people[i][1];
            int temp = i;
            while (currPos != temp) {
                swap(people[temp], people[temp - 1]);
                temp --;
            }
        }
        return people;
    }
};