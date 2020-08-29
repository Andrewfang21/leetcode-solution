class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> q;
        for (int stone : stones)
            q.push(stone);
        
        while (q.size() > 1) {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            
            if (first - second != 0)
                q.push(first - second);
        }
        
        return q.empty() ? 0 : q.top();
    }
};
