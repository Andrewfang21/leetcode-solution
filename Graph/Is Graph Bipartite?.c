#define N 105
int G[N][N];
int color[N];

int fail = 0;

void dfs(int pos, int graphSize) {
    if (fail) {
        return;
    }
    
    for (int next = 0; next < graphSize; next ++) {
        if (G[pos][next] == 0)
            continue;
        
        if (color[next] == -1) {
            color[next] = 1 - color[pos];
            dfs(next, graphSize);
            
            continue;
        }
        
        if (color[pos] == color[next]) {
            fail = 1;
            return;
        }
    }
}

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    memset(G, 0, sizeof(G));
    for (int i = 0; i < graphSize; i ++) {
        for (int j = 0; j < graphColSize[i]; j ++) {
            int from , to;
            from = i;
            to = graph[i][j];
            
            G[from][to] = 1;
        }
    }
    
    memset(color, -1, sizeof(color));
    fail = 0;
    for (int i = 0; i < graphSize; i ++) {
        if (color[i] == -1) {
            color[i] = 1;
            dfs(i, graphSize);
            
            if (fail) {
                return 0;
            }
        }
    }
    
    if (fail)
        return 0;
return 1;
}

