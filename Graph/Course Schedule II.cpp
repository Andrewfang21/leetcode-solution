class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int inDeg[numCourses];
        memset(inDeg, 0, sizeof(inDeg));
        
        vector<int> adj[numCourses];
        for (int i = 0; i < numCourses; i ++)
            adj[i].clear();
        
        for (int i = 0; i < prerequisites.size(); i ++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            
            adj[from].push_back(to);
            inDeg[to] ++;
        }
        
        vector<int> order;
        queue<int> Q;
        
        for (int i = 0; i < numCourses; i ++)
            if (inDeg[i] == 0)
                Q.push(i);
        
        while (!Q.empty()) {
            int pos = Q.front();
            Q.pop();
            
            order.push_back(pos);
            for (int next : adj[pos]) {
                inDeg[next] --;
                if (inDeg[next] == 0)
                    Q.push(next);
            }
        }
        
        if (order.size() != numCourses)
            order.clear();
        
        return order;
    }
};