class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        typedef pair<int, pair<int, int>> pii;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        vector<pair<int, int>> adj[10005];
        
        for (vector<int> f : flights) {
            int u = f[0], v = f[1], w = f[2];
            adj[u].emplace_back(v, w);    
        }
        
        q.push(make_pair(0, make_pair(src, K)));
        while (!q.empty()) {
            pii curr = q.top();
            q.pop();

            if (curr.second.first == dst)
                return curr.first;
            
            for (pair<int, int> next : adj[curr.second.first]) {
                if (curr.second.second >= 0) {
                    q.push(make_pair(curr.first + next.second,
                                     make_pair(next.first, curr.second.second - 1)));
                }
            }
        }
        return -1;
    }
};