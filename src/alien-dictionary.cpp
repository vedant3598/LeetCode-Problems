class Solution {
    unordered_map<char, vector<char>> adj;
    set<char> visited;
    string reverse = "";
public:
    bool dfs(char c){
        if(visited.find(c) != visited.end()){
            return false;
        }

        visited.insert(c);
        for(int i = 0; i < adj[c].size(); i++){
            if(!dfs(adj[c][i])){
                return false;
            }
        }
        visited.erase(c);
        reverse.push_back(c);
        return true;
    }

    string alienOrder(vector<string> &words) {
        for(string word : words){
            for(int i = 0; i < word.length(); i++){
                adj[word[i]] = {};
            }
        }

        for(int i = 0; i < words.size() - 1; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int minLen = min(w1.length(), w2.length());
            if(w1.length() > w2.length && w1.substr(0, minLen) == w2.substr(0, minLen)){
                return "";
            }
            for(int j = 0; j < minLen; j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    break;
                }
            }
        } 

        for(unordered_map<char, vector<char>>::iterator it = adj.begin(); it != adj.end(); it++){
            if(!dfs(it->first)){
                return "";
            }
        }   

        string sol = "";
        for(int i = reverse.length() - 1; i != -1; i--){
            sol += reverse[i];
        }
        return sol;
    }
};
