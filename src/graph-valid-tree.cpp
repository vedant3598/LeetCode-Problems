class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    map<int, vector<int>> adj;
    set<int> visited;
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
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if(!dfs(0, -1)){
            return false;
        }

        if(visited.size() == n)
            return true;
        return false;
    }
};
