class Solution {
public:
    int kSimilarity(string A, string B) {
        queue<string> Q;
        Q.push(A);
        
        map<string, int> vis;
        vis[A] = 1;
        while (!Q.empty()) {
            string curr = Q.front();
            Q.pop();
            
            int step = vis[curr];
            if (curr == B)
                return step - 1;                
            
            for (int i = 0; i < curr.length(); i ++) {
                if (curr[i] == B[i])
                    continue;
                
                for (int j = i + 1; j < curr.length(); j ++) {
                    if (i == j)
                        continue;
                    if (curr[i] != B[j])
                        continue;
                    
                    swap(curr[i], curr[j]);
                    if (vis[curr] == 0) {
                        Q.push(curr);
                        vis[curr] = step + 1;
                    }
                    swap(curr[i], curr[j]);
                }
                break;
            }
        }
        
        return vis[B] - 1;
    }
};