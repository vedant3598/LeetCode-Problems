class Solution {
private:
    unordered_map<char, vector<char>> adj;
    map<char, bool> visited;
    string sol = "";
public:
    bool dfs(char c){
        if(visited.find(c) != visited.end()){
            return visited[c];
        }

        visited[c] = true;
        for(int i = 0; i < adj[c].size(); i++){
            if(dfs(adj[c][i])){
                return true;
            }
        }
        visited[c] = false;
        sol = c + sol;
        return false;
    }

    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        for(int i = 0; i < words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int minLen = min(w1.length(), w2.length());
            if(w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)){
                return "";
            }
            for(int j = 0; j < minLen; j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        }

        for(auto it = adj.begin(); it != adj.end(); it++){
            if(dfs(it->first)){
                return "";
            }
        }
        return sol;
    }
};
