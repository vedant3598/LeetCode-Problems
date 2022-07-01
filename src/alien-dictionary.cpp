class Solution {
public:
    map<char, set<char>> adj;
    string reverse;
    set<char> path;

    bool dfs(char c){
        if(path.find(c) != path.end()){
            return true;
        }

        path.insert(c);
        for(int i = 0; i < adj[c].size(); i++){
            if(dfs(adj[c][i])){
                return true;
            }
        }
        path.erase(c);
        reverse.push_back(c);
        return false;
    }

    string alienOrder(vector<string> &words) {
        map<char, set<char>> adj;
        for(int i = 0; i < words.size() - 1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int minLen = min(word1.length(), word2.length());
            if(word1.length() > word2.length() && word1.substr(0, minLen) == word2.substr(0, minLen)){
                return "";
            }
            for(int j = 0; j < minLen; j++){
                if(word1[j] != word2[j]){
                    adj[word1[j]].insert(word2[j]);
                    break;
                }
            }
        }

        for(auto const& c : adj){
            if(dfs(c.first)){
                return "";
            }
        }

        string sol = "";

        for(int i = reverse.length() - 1; i >= 0; i--){
            sol += reverse[i];
        }
        return sol;

    }
};
