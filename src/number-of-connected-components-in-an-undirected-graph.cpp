class Solution{
    map<int, vector<int>> adj;
    set<int> visited;
public:
    void dfs(int node){
        visited.insert(node);
        
        for(int i = 0; i < adj[node].size(); i++){
            if(visited.find(adj[node][i]) == visited.end()){
                dfs(adj[node][i], node);
            }
        }
    }

    int connectedComponents(int n, vector<vector<int>> &edges){
        int components = 0;
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i < n; i++){
            if(visited.find(i) == visited.end()){
                dfs(i);
                components++;
            }
        }
        return components;
    }
};
