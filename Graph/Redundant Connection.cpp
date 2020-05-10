const int N = 1005;

class Solution {
public:
    int par[N], height[N];

    int findSet(int pos) {
        if (par[pos] == pos)
            return pos;
        return par[pos] = findSet(par[pos]);
    }
    
    bool sameSet(int u, int v) {
        return findSet(u) == findSet(v);
    }
    
    void mergeSet(int u, int v, int height[]) {
        int x = findSet(u);
        int y = findSet(v);
        
        if (height[x] >= height[y]) {
            par[y] = x;
            height[x] ++;
        }
        else {
            par[x] = y;
            height[y] ++;
        }
        
        if (height[x] == height[y])
            height[x] ++;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 1; i < N; i ++) {
            par[i] = i;
            height[i] = 1;
        }
            
        vector<int> ans;
        for (vector<int> edge : edges) {
            int from = edge[0];
            int to = edge[1];
            
            if (!sameSet(from, to))
                mergeSet(from, to, height);
            else
                ans.push_back(from), ans.push_back(to);
        }
        
        return ans;
    }
};