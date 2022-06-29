    set<int> visited;
    map<int, vector<int>> adj;
    
    void dfs(int node){
        if(visited.find(node) != visited.end())
            return;
        
        visited.insert(node);
        for(int i = 0; i < adj[node].size(); i++){
            dfs(adj[node][i]);
        }
    }
    
    int connectedComponents(int n, vector<vector<int>>& edges){
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int sol = 0;
        for(int i = 0; i < n; i++){
            if(visited.find(i) == visited.end()){
                dfs(i);
                sol++;
            }            
        }
        return sol;
    }
