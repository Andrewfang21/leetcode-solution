class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        typedef pair<int, int> pii;
        priority_queue<pii, vector<pii>, greater<pii>>q;
        vector<pii> adj[N + 5];
        
        for (vector<int> t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].emplace_back(v, w);
        }
        
        int vis[N + 5];
        for (int i = 1; i <= N; i ++)
            vis[i] = INT_MAX;
        
        vis[K] = 0;
        q.emplace(0, K);
        while (!q.empty()) {
            pii curr = q.top();
            q.pop();
            
            for (pii next : adj[curr.second]) {
                if (vis[next.first] > vis[curr.second] + next.second) {
                    vis[next.first] = vis[curr.second] + next.second;
                    q.emplace(vis[next.first], next.first);
                }
            }
        }
        
        int res = INT_MIN, cnt = 0;
        for (int i = 1; i <= N; i ++) {
            if (vis[i] != INT_MAX) {
                cnt ++;
                res = max(res, vis[i]);
            }
        }
        
        return (cnt == N) ? res : -1;
    }
};