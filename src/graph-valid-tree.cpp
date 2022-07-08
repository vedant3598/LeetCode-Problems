class Solution {
    map<int, vector<int>> adj;
    set<int> visited;
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */

    bool dfs(int node, int prev){
        if(visited.find(node) != visited.end()){
            return false;
        }
        
        visited.insert(node);
        for(int i = 0; i < adj[node].size(); i++){
            if(adj[node][i] != prev){
                if(!dfs(adj[node][i], node)){
                    return false;
                }
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>> &edges) {
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        if(!dfs(0, -1) || visited.size() != n){
            return false;
        }

        return true;
    }
};
