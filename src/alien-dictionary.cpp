class Solution {
    map<char, set<char>> adj;
    set<char> visited;
    string reverse = "";
public:
    bool dfs(char c){
        if(visited.find(c) != visited.end()){
            return true;
        }

        visited.insert(c);
        for(set<int>::iterator it = adj[c].begin(); it != adj[c].end(); it++){
            if(dfs(*it)){
                return true;
            }
        }
        visited.erase(c);
        reverse.push_back(c);
        return false;
    }

    string alienOrder(vector<string> &words) {
        for(int i = 0; i < words.size() - 1; i++){
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

        for (std::map<char,set<char>>::iterator it=adj.begin(); it!=adj.end(); ++it){
            if(dfs(*it)){
                return "";
            }
        }

        string sol = "";
        for(int i = reverse.length() - 1; i != -1; i--){
            sol += reverse[i];
        }
        retur sol;
    }
};
