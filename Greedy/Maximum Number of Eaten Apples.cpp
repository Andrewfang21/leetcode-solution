class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        typedef pair<int, int> pii;
        priority_queue<pii, vector<pii>, greater<pii>>pq;

        int eatenApples = 0;
        for(int day = 0 ; day < days.size() || !pq.empty(); day ++) {
            if (day < apples.size() && apples[day] != 0 && days[day] != 0)
                pq.emplace(day + days[day], apples[day]);

            while (!pq.empty() && pq.top().first <= day)
                pq.pop();

            if (!pq.empty()) {
                pii currApples = pq.top();
                pq.pop();
                
                if (day >= apples.size()) {
                    int applesNow = min(currApples.first - day, currApples.second);
                    eatenApples += applesNow;
                    day += applesNow - 1;
                } else {
                    eatenApples ++;
                    currApples.second --;
                    if (currApples.second > 0)
                        pq.emplace(currApples);
                }
            }
        }    
        return eatenApples;
    }
};